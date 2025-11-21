#include <cstdint>
#include <cstdio>
#include <cstring>
#include <random>
#include <fstream>
#include <unordered_set>
#include <omp.h>
#include <thread>
#define XXH_INLINE_ALL
#include "xxhash.h"
#include <ctime>

#define START_TIMER { auto start = clock();
#define END_TIMER(name) printf("%s: %.2f ms\n", name, (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
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
char staticShortLine[54];
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
  for (char i = 0; i < 6; i++) {
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
    move((uint64_t(rng()) * 16) >> 32);
  }
}

void staticSave () {
  for (size_t i = 0; i < 54; i++) {
    staticShortLine[i] = *shortLine[i];
  }
}

bool isEdgeOriented(char face1, char pos1, char face2, char pos2) {
    char color1 = pixels[face1][pos1];
    char color2 = pixels[face2][pos2];
    
    // Si l'aresta toca U o D, ha de tenir w o y a la cara U/D
    if (face1 == 1 || face1 == 3) {  // face1 és U o D
        return (color1 == 'w' || color1 == 'y');
    }
    if (face2 == 1 || face2 == 3) {  // face2 és U o D
        return (color2 == 'w' || color2 == 'y');
    }
    
    // Si l'aresta no toca U ni D, no ha de tenir w ni y
    return (color1 != 'w' && color1 != 'y' && 
            color2 != 'w' && color2 != 'y');
}

// Verifica si una cantonada està ben orientada
// Les cantonades estan ben orientades si el sticker w/y mira cap a U/D
bool isCornerOriented(char faceUD, char posUD) {
    char color = pixels[faceUD][posUD];
    return (color == 'w' || color == 'y');
}

// Verifica si les 4 arestes del middle slice estan al seu lloc
// En G1, les arestes FR, FL, BR, BL han d'estar entre les capes U i D
bool areMiddleEdgesInSlice() {
    // Compta quantes arestes de middle slice estan al middle slice
    int count = 0;
    
    // Aresta Front-Right (entre F i R, posició middle)
    char fr1 = pixels[0][5];  // Front middle-right
    char fr2 = pixels[5][3];  // Right middle-left
    if ((fr1 == 'g' && fr2 == 'r') || (fr1 == 'r' && fr2 == 'g')) count++;
    
    // Aresta Front-Left (entre F i L, posició middle)
    char fl1 = pixels[0][3];  // Front middle-left
    char fl2 = pixels[4][5];  // Left middle-right
    if ((fl1 == 'g' && fl2 == 'o') || (fl1 == 'o' && fl2 == 'g')) count++;
    
    // Aresta Back-Right (entre B i R, posició middle)
    char br1 = pixels[2][3];  // Back middle-left
    char br2 = pixels[5][5];  // Right middle-right
    if ((br1 == 'b' && br2 == 'r') || (br1 == 'r' && br2 == 'b')) count++;
    
    // Aresta Back-Left (entre B i L, posició middle)
    char bl1 = pixels[2][5];  // Back middle-right
    char bl2 = pixels[4][3];  // Left middle-left
    if ((bl1 == 'b' && bl2 == 'o') || (bl1 == 'o' && bl2 == 'b')) count++;
    
    return count == 4;
}

bool isG1() {
    // 1. ORIENTACIÓ DE LES 12 ARESTES
    
    // Arestes que toquen U (cara 1)
    if (!isEdgeOriented(1, 1, 0, 1)) return false;  // U-F
    if (!isEdgeOriented(1, 3, 4, 1)) return false;  // U-L
    if (!isEdgeOriented(1, 5, 5, 1)) return false;  // U-R
    if (!isEdgeOriented(1, 7, 2, 1)) return false;  // U-B
    
    // Arestes que toquen D (cara 3)
    if (!isEdgeOriented(3, 1, 0, 7)) return false;  // D-F
    if (!isEdgeOriented(3, 3, 4, 7)) return false;  // D-L
    if (!isEdgeOriented(3, 5, 5, 7)) return false;  // D-R
    if (!isEdgeOriented(3, 7, 2, 7)) return false;  // D-B
    
    // Arestes del middle slice (no toquen U ni D)
    if (!isEdgeOriented(0, 3, 4, 5)) return false;  // F-L
    if (!isEdgeOriented(0, 5, 5, 3)) return false;  // F-R
    if (!isEdgeOriented(2, 3, 5, 5)) return false;  // B-R
    if (!isEdgeOriented(2, 5, 4, 3)) return false;  // B-L
    
    // 2. ORIENTACIÓ DE LES 8 CANTONADES
    // Les cantonades han de tenir w/y a les cares U/D
    if (!isCornerOriented(1, 0)) return false;  // ULF
    if (!isCornerOriented(1, 2)) return false;  // URF
    if (!isCornerOriented(1, 6)) return false;  // ULB
    if (!isCornerOriented(1, 8)) return false;  // URB
    if (!isCornerOriented(3, 0)) return false;  // DLF
    if (!isCornerOriented(3, 2)) return false;  // DRF
    if (!isCornerOriented(3, 6)) return false;  // DLB
    if (!isCornerOriented(3, 8)) return false;  // DRB
    
    // 3. LES 4 ARESTES DEL MIDDLE SLICE HAN D'ESTAR AL SLICE
    if (!areMiddleEdgesInSlice()) return false;
    
    return true;
}

int heuristicEdges() {
    int count = 0;
    // comprova totes les 12 arestes
    if (!isEdgeOriented(1, 1, 0, 1)) count++; // U-F
    if (!isEdgeOriented(1, 3, 4, 1)) count++; // U-L
    if (!isEdgeOriented(1, 5, 5, 1)) count++; // U-R
    if (!isEdgeOriented(1, 7, 2, 1)) count++; // U-B
    if (!isEdgeOriented(3, 1, 0, 7)) count++; // D-F
    if (!isEdgeOriented(3, 3, 4, 7)) count++; // D-L
    if (!isEdgeOriented(3, 5, 5, 7)) count++; // D-R
    if (!isEdgeOriented(3, 7, 2, 7)) count++; // D-B
    if (!isEdgeOriented(0, 3, 4, 5)) count++; // F-L
    if (!isEdgeOriented(0, 5, 5, 3)) count++; // F-R
    if (!isEdgeOriented(2, 3, 5, 5)) count++; // B-R
    if (!isEdgeOriented(2, 5, 4, 3)) count++; // B-L

    return (count + 3) / 4; // ceil(count/4)
}

bool solverG1(char depth, char lastMove = 100, char lastMove2 = 100) {
  if (isG1()) return true;
  
  if (depth != 0 && depth >= heuristicEdges()) {
    for(char i = 0; i < 16; i++) {
      if (lastMove != 100 && i == reverse[lastMove]) continue;
      
      if (lastMove != 100 && lastMove2 != 100) {
        if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
      }
      if ((i < 4 && i > 7) && i == lastMove) continue;

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
  for (char depth = 0; depth <= 12; depth++) {
    if (isG1() == true) return true;
    printf("Buscando profundidad %d...\n", depth);
    if (solverG1(depth)) {
      printf("✓ Solución encontrada en profundidad %d\n", depth);
      return true;
    }
  }
  printf("✗ No se encontró solución hasta profundidad 12\n");
  return false;
}

int g2Counter = 0;

__uint128_t* onlineHashes = new __uint128_t[47380816];
uint8_t* onlineMoves = new uint8_t[47380816];

void searchG2(char depth=9, char lastMove = 100, char lastMove2 = 100) {
  char equal = 0;
  for (char i = 0; i < 72; i++) {
    if (perfectLine[i]==*line[i]) equal ++;
  }
  if (depth == 0 || equal==72) {
    return;
  }

  char legalMoves[8] = {4, 5, 6, 7, 12, 13, 14, 15};

  for(char i : legalMoves) {
    if (lastMove != 100 && i == reverse[lastMove]) continue;
    if (lastMove != 100 && lastMove2 != 100) {
      if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
    }
    if ((i < 4 && i > 7) && i == lastMove) continue;
    move(i);
    char buffer[54];
    for (int i = 0; i < 54; i++) buffer[i] = *shortLine[i];
    XXH128_hash_t h = XXH3_128bits(buffer, 54);
    onlineHashes[g2Counter] = (__uint128_t(h.high64) << 64) | h.low64;
    onlineMoves[g2Counter] = reverse[i];
    g2Counter++;
    searchG2(depth-1, i, lastMove);
    move(reverse[i]);
  }
}

__uint128_t objective;
int objectiveIndex;

void findMiddle () {
  char equal = 0;
  std::unordered_set<__uint128_t> s;
  s.reserve(counter);
  for (char i = 0; i < 72; i++) {
    if (perfectLine[i]==*line[i]) equal ++;
  }
  if (equal == 72) return;
  for (size_t i = 0; i < counter; i++) {
    s.insert(onlineHashes[i]);
  }
  #pragma omp parallel for
  for (size_t i = 0; i < counter; i++) {
    if (s.count(hashes[i])) {
      #pragma omp critical
      //printf("COINCIDENCIA!!! Hash: %llu\n", hashes[i]);
      objectiveIndex = i;
      objective = hashes[i];
    }
  }
}

bool solve () {
  bool found = false;
  char equal = 0;
  for (char i = 0; i < 72; i++) {
    if (perfectLine[i]==*line[i]) equal ++;
  }
  while (equal!=72 && !found) {
    for (char i = 0; i < 72; i++) {
      if (perfectLine[i]==*line[i]) equal ++;
    }
    if (equal == 72) return true;
    char buffer[54];
    for (int i = 0; i < 54; ++i) buffer[i] = *shortLine[i];
    XXH128_hash_t h = XXH3_128bits(buffer, 54);
    __uint128_t hash = (__uint128_t(h.high64) << 64) | h.low64;
  
    #pragma omp parallel for
    for (int i = 0; i < counter; i++) {
      if (hash == hashes[i]) {
        #pragma omp critical
        //printf("COINCIDENCIA!\n");
        move(moves[i]);
        solution[solutionIndex] = moves[i];
        solutionIndex++;
        found = true;
      }
    }
  }
  return true;
}

bool solverG2(char depth=9, char lastMove = 100, char lastMove2 = 100) {
  char equal = 0;
  for (char i = 0; i < 72; i++) {
    if (perfectLine[i]==*line[i]) equal ++;
  }
  if (equal == 72) return true;
  char buffer[54];
  for (int i = 0; i < 54; ++i) buffer[i] = *shortLine[i];
  XXH128_hash_t h = XXH3_128bits(buffer, 54);
  __uint128_t hash = (__uint128_t(h.high64) << 64) | h.low64;
  if (hash == objective) {
    //printf("COINCIDENCIA!\n");
    move(moves[objectiveIndex]);
    solution[solutionIndex] = moves[objectiveIndex];
    solutionIndex++;
    return solve();
    }
  char legalMoves[8] = {4, 5, 6, 7, 12, 13, 14, 15};
  if (depth != 0) {
    for(char i : legalMoves) {
      if (lastMove != 100 && i == reverse[lastMove]) continue;

      if (lastMove != 100 && lastMove2 != 100) {
        if (i/2 == lastMove/2 && lastMove/2 == lastMove2/2) continue;
      }

      solution[solutionIndex] = i;
      solutionIndex++;
      move(i);

      if (solverG2(depth-1, i, lastMove)) return true;

      move(reverse[i]);
      solutionIndex--;
    }
  }
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
/*
int main () {
  savesLine();
  loadFromBinary();
  mix(8);
  staticSave();
  print();
  if (solverG1Iterative()) printf("Kociemba OK\n");
  searchG2();
  findMiddle();
  if (solverG2()) printf("SOLVED\n");
  path();
  print();
}
*/

int main () {
  savesLine();
  
  std::thread t1([]{ 
    auto start = clock();
    loadFromBinary();
    printf("loadFromBinary: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); 
  });
  
  { auto start = clock();
  mix(8);
  printf("mix: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  staticSave();
  
  { auto start = clock();
  if (solverG1Iterative()) printf("Kociemba OK\n");
  printf("solverG1Iterative: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  t1.join();
  
  { auto start = clock();
  searchG2();
  printf("searchG2: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  { auto start = clock();
  findMiddle();
  printf("findMiddle: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  { auto start = clock();
  if (solverG2()) printf("SOLVED\n");
  printf("solverG2: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  { auto start = clock();
  path();
  printf("path: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
  
  { auto start = clock();
  print();
  printf("print: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000); }
}
