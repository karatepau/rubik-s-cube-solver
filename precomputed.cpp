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
char* shortLine[45];
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
      line[k+24] = &pixels[permUD[i]][permULine[k]];
      line[k+36] = &pixels[permUD[i]][permDLine[k]];
      line[k+48] = &pixels[permFB[i]][permFLine[k]];
      line[k+60] = &pixels[permFB[i]][permBLine[k]];
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

long long counter = 0;

__uint128_t* hashes = new __uint128_t[47380816];
uint8_t* moves = new uint8_t[47380816];

void search(char depth, char lastMove = 255, char lastMove2 = 255) {
  if (depth == 0) {
    return;
  }
  
  char legalMoves[8] = {4, 5, 6, 7, 12, 13, 14, 15};
  
  for(char i : legalMoves) {
    if (lastMove != 255 && i == reverse[lastMove]) continue;
    if (lastMove != 255 && lastMove2 != 255) {
      if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
    }
    
    move(i);
    uint8_t buffer[45];
    for (int i = 0; i < 45; i++) buffer[i] = *shortLine[i];
    XXH128_hash_t h = XXH3_128bits(buffer, 45);
    hashes[counter] = (__uint128_t(h.high64) << 64) | h.low64;
    moves[counter] = reverse[i];
    counter++;
    search(depth-1, i, lastMove);
    move(reverse[i]);
  }
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

void saveToTxt () {
  std::ofstream f("precalculatedPositions.txt");

  // Primer array (hashes)
  for (long long i = 0; i < counter; i++) {
  // __uint128_t no té operadors de sortida per defecte
    unsigned long long high = (unsigned long long)(hashes[i] >> 64);
    unsigned long long low  = (unsigned long long)(hashes[i] & 0xFFFFFFFFFFFFFFFFULL);
    f << high << "_" << low << " "; // separo alta i baixa part
  }
  f << "\n";

    // Segon array (moves)
  for (long long i = 0; i < counter; i++) {
    f << (unsigned int)moves[i] << " ";
  }
  f << "\n";
  f.close();
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
  search(9);
  printf("Total camins explorats: %lld\n", counter);
  saveToTxt();  
}
