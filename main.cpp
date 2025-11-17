#include <cstdint>
#include <cstdio>
#include <cstring>
#include <random>
#include <fstream>
#define XXH_INLINE_ALL
#include "xxhash.h"

//3d cube represented with a 2d matrix, 6 faces with 9 colors/pixels inside each of one
alignas(64) char pixels[6][9]={
  {'g', 'g', 'g',
   'g', 'g', 'g',
   'g', 'g', 'g'},

  {'w', 'w', 'w',
   'w', 'w', 'w',
   'w', 'w', 'w'},

  {'b', 'b', 'b',
   'b', 'b', 'b',
   'b', 'b', 'b'},

  {'y', 'y', 'y',
   'y', 'y', 'y',
   'y', 'y', 'y'},

  {'o', 'o', 'o',
   'o', 'o', 'o',
   'o', 'o', 'o'},

  {'r', 'r', 'r',
   'r', 'r', 'r',
   'r', 'r', 'r'},
};

enum movements : uint8_t {  // 1 byte en vez de 4
    LPrime = 0,
    L,
    R,
    RPrime,
    U,
    UPrime,
    DPrime,
    D,
    F,
    FPrime,
    BPrime,
    B
};

//Save of all the lines (edges+corners), his static copy (the same but without being a pointer) and a copy for sides
char* line[72];
char* shortLine[54];
char staticLine[12];
char lateral[9];

//Permutation of the lines that are going to rotate
const char permDown[12] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
const char permUp[12] = {9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8};

//Permutation of the laterals when they are rotated
const char permLateralDown[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
const char permLateralUp[9] = {2, 5, 8, 1, 4, 7, 0, 3, 6};

//List of indexes (of the faces) to follow in the loop for saving the line
const char permUD[4] = {0, 4, 2, 5};
const char permFB[4] = {1, 5, 3, 4};

//Order of saving the pixels inside the line
const char permULine[12] = {0, 1, 2, 0, 1, 2, 8, 7, 6, 0, 1, 2};
const char permDLine[12] = {6, 7, 8, 0, 3, 6, 2, 1, 0, 8, 7, 6};

const char permBLine[12] = {0, 1, 2, 2, 5, 8, 8, 7, 6, 6, 3, 0};
const char permFLine[12] = {6, 7, 8, 0, 3, 6, 2, 1, 0, 8, 5, 2};

char perfectLine[72] = {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b',
                        'y', 'y', 'y', 'g', 'g', 'g', 'w', 'w', 'w',
                        'b', 'b', 'b', 'y', 'y', 'y', 'g', 'g', 'g',
                        'o', 'o', 'o', 'b', 'b', 'b', 'r', 'r', 'r',
                        'g', 'g', 'g', 'o', 'o', 'o', 'b', 'b', 'b',
                        'r', 'r', 'r', 'w', 'w', 'w', 'r', 'r', 'r',
                        'y', 'y', 'y', 'o', 'o', 'o', 'w', 'w', 'w',
                        'r', 'r', 'r', 'y', 'y', 'y', 'o', 'o', 'o'};

char reverse [16] = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 12, 13, 14, 15};

char solution[30];
char solutionIndex = 0;

void print();

static inline void spinLateral (char side, const char perm[9]) {
  memcpy(lateral, pixels[side], sizeof(lateral));
  for (char i = 0; i < 9; i++) {
    pixels[side][i]=lateral[perm[i]];
  }
}

static inline void savesLine () {
  char k = 0;
  for (char i = 0; i < 4; i++) {
    for (char j = 0; j < 7; j += 3) {
      line[k] = &pixels[i][j];
      line[k+12] = &pixels[i][j+2];
      line[k+24]= &pixels[permUD[i]][permULine[k]];
      line[k+36]= &pixels[permUD[i]][permDLine[k]];
      line[k+48]= &pixels[permFB[i]][permFLine[k]];
      line[k+60]= &pixels[permFB[i]][permBLine[k]];
      k++;
    }
  }
  k=0;
  for (char i = 0; i < 5; i++) {
    for (char j = 0; j < 9; j++) {
      shortLine[k] = &pixels[i][j];
      k++;
    }
  }
}

__uint128_t* hashes = nullptr;
uint8_t* moves = nullptr;
uint64_t counter = 0;

void loadFromBinary() {
  std::ifstream f("precalculatedPositions.bin", std::ios::binary);

  if (!f) {
    printf("File not found\n");
    return;
    }

  // Read counter
  f.read(reinterpret_cast<char*>(&counter), sizeof(counter));

  hashes = new __uint128_t[counter];
  moves  = new uint8_t[counter];

  // Read
  f.read(reinterpret_cast<char*>(hashes), counter * sizeof(__uint128_t));
  f.read(reinterpret_cast<char*>(moves), counter * sizeof(uint8_t));

  f.close();
}

static inline void spinLine (char side, const char perm[12]) {
  for (char i = 0; i < 12; i++) {
    staticLine[i] = *line[i+side];
  }
  for (char i = 0; i < 12; i++) {
    *line[i+side]=staticLine[perm[i]];
  }
}

static inline void move (char option) {
  switch (option) {
    case 0: // LPrime
      spinLine (0, permUp);
      spinLateral (4, permLateralUp);
      break;
    case 1: // L
      spinLine (0, permDown);
      spinLateral (4, permLateralDown);
      break;
    case 2: // R
      spinLine (12, permUp);
      spinLateral (5, permLateralDown);
      break;
    case 3: // RPrime
      spinLine (12, permDown);
      spinLateral (5, permLateralUp);
      break;
    case 4: // U
      spinLine (24, permUp);
      spinLateral (1, permLateralDown);
      break;
    case 5: // UPrime
      spinLine (24, permDown);
      spinLateral (1, permLateralUp);
      break;
    case 6: // DPrime
      spinLine (36, permUp);
      spinLateral (3, permLateralUp);
      break;
    case 7: // D
      spinLine (36, permDown);
      spinLateral (3, permLateralDown);
      break;
    case 8: // F
      spinLine (48, permUp);
      spinLateral (0, permLateralDown);
      break;
    case 9: // FPrime
      spinLine (48, permDown);
      spinLateral (0, permLateralUp);
      break;
    case 10: // BPrime
      spinLine (60, permUp);
      spinLateral (2, permLateralUp);
      break;
    case 11: // B
      spinLine (60, permDown);
      spinLateral (2, permLateralDown);
      break;
    case 12:  // R2
      spinLine (12, permUp);
      spinLateral (5, permLateralDown);
      spinLine (12, permUp);
      spinLateral (5, permLateralDown);
      break;
    case 13:  // L2
      spinLine (0, permDown);
      spinLateral (4, permLateralDown);
      spinLine (0, permDown);
      spinLateral (4, permLateralDown);
      break;
    case 14:  // F2
      spinLine (48, permUp);
      spinLateral (0, permLateralDown);
      spinLine (48, permUp);
      spinLateral (0, permLateralDown);
      break;
    case 15:  // B2
      spinLine (60, permDown);
      spinLateral (2, permLateralDown);
      spinLine (60, permDown);
      spinLateral (2, permLateralDown);
      break;
  }
}

void mix (int times_mixed) {
  static std::mt19937 rng(std::random_device{}());
  for (int i = 0; i < times_mixed; i++) {
    move((uint64_t(rng()) * 12) >> 32);
  }
}

inline bool isMS(char c1, char c2) {
  return ((c1=='g'||c1=='b')&&(c2=='r'||c2=='o'))||
         ((c2=='g'||c2=='b')&&(c1=='r'||c1=='o'));
}

bool isG1() {
  return pixels[0][7]!='w'&&pixels[0][7]!='y'&&
         pixels[0][1]!='w'&&pixels[0][1]!='y'&&
         pixels[2][7]!='w'&&pixels[2][7]!='y'&&
         pixels[2][1]!='w'&&pixels[2][1]!='y'&&
         pixels[4][7]!='w'&&pixels[4][7]!='y'&&
         pixels[4][1]!='w'&&pixels[4][1]!='y'&&
         pixels[5][7]!='w'&&pixels[5][7]!='y'&&
         pixels[5][1]!='w'&&pixels[5][1]!='y'&&
         !isMS(pixels[1][5],pixels[5][7])&&
         !isMS(pixels[1][3],pixels[4][7])&&
         !isMS(pixels[3][5],pixels[5][1])&&
         !isMS(pixels[3][3],pixels[4][1]);
}

bool solverG1(char depth, char lastMove = 255, char lastMove2 = 255) {
  if (isG1()) return true;
  
  if (depth != 0) {
    for(char i = 0; i < 16; i++) {
      if (lastMove != 255 && i == reverse[lastMove]) continue;
      
      if (lastMove != 255 && lastMove2 != 255) {
        if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
      }
      
      solution[solutionIndex] = i;
      solutionIndex++;
      move(i);
      
      if (solverG1(depth-1, i, lastMove)) return true;
      
      move(reverse[i]);
      solutionIndex--;
    }
  }
  return false;
}

bool solverG1Iterative() {
  for (char depth = 1; depth <= 8; depth++) {
    if (isG1() == true) return true;
    printf("Buscando profundidad %d...\n", depth);
    if (solverG1(depth)) {
      printf("✓ Solución encontrada en profundidad %d\n", depth);
      return true;
    }
  }
  printf("✗ No se encontró solución hasta profundidad 5\n");
  return false;
}

bool solverG2Iterative();

bool solverG2(char depth, char lastMove = 255, char lastMove2 = 255) {
  char buffer[45];
  memcpy (buffer, *shortLine, sizeof(buffer));
  XXH128_hash_t h = XXH3_128bits(buffer, 45); // 128-bit hash
  __uint128_t hash = (__uint128_t(h.high64) << 64) | h.low64;
  for (char i = 0; i < counter; i++) {
    if (hash == hashes[i]) {
      move(moves[i]);
      solution[solutionIndex] = moves[i];
      solutionIndex++;
      solverG2Iterative();
      return false;
    }
  }
  if ()
  char legalMoves[8] = {4, 5, 6, 7, 12, 13, 14, 15};
  if (depth != 0) {
    for(char i : legalMoves) {
      if (lastMove != 255 && i == reverse[lastMove]) continue;

      if (lastMove != 255 && lastMove2 != 255) {
        if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
      }

      solution[solutionIndex] = i;
      solutionIndex++;
      move(i);

      if (solverG1(depth-1, i, lastMove)) return true;

      move(reverse[i]);
      solutionIndex--;
    }
  }
  return false;
}

bool solverG2Iterative() {
  for (char depth = 1; depth <= 9; depth++) {
    if (isG1() == true) return true;
    printf("Buscando profundidad %d...\n", depth);
    if (solverG1(depth)) {
      printf("✓ Solución encontrada en profundidad %d\n", depth);
      return true;
    }
  }
  printf("✗ No se encontró solución hasta profundidad 5\n");
  return false;
}

void path () {
  for (char i = 0; i < solutionIndex; i++) {
   switch (solution[i]) {
  case 0:
    printf("LPrime\n");
    break;
  case 1:
    printf("L\n");
    break;
  case 2:
    printf("R\n");
    break;
  case 3:
    printf("RPrime\n");
    break;
  case 4:
    printf("U\n");
    break;
  case 5:
    printf("UPrime\n");
    break;
  case 6:
    printf("DPrime\n");
    break;
  case 7:
    printf("D\n");
    break;
  case 8:
    printf("F\n");
    break;
  case 9:
    printf("FPrime\n");
    break;
  case 10:
    printf("BPrime\n");
    break;
  case 11:
    printf("B\n");
    break;
  case 12:
    printf("R2\n");
    break;
  case 13:
    printf("L2\n");
    break;
  case 14:
    printf("F2\n");
    break;
  case 15:
    printf("B2\n");
    break;
  }
  }
}

void print () {
  char k = 0;
  for (char i = 0; i < 6; i++) {
    k = 0;
    for (char j = 0; j < 3; j++) {
      for (char l = 0; l < 3; l++) {
        printf("%c ",pixels[i][k]);
        k++;
      }
      printf("\n");
    }
    printf("\n");
  }
}

int main () {
  savesLine();
  loadFromBinary();
  mix(100000);
  print();
  if (solverG1Iterative()) printf("Kociemba OK\n");
  if (solverG2Iterative()) printf("All OK\n");
  path();
  print();
}
