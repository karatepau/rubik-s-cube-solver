#include <cstdio>
#include <cstring>

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

//Save of all the lines (edges+corners), his static copy (the same but without being a pointer) and a copy for sides
char* line[72];
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
const char permDLine[12] = {6, 7, 8, 6, 7, 8, 2, 1, 0, 6, 7, 8};

const char permBLine[12] = {0, 1, 2, 2, 5, 8, 8, 7, 6, 6, 3, 0};
const char permFLine[12] = {6, 7, 8, 0, 3, 6, 8, 7, 6, 8, 5, 2};

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
    case 1:
      spinLine (0, permUp);
      break;
    case 2:
      spinLine (0, permDown);
      break;
    case 3:
      spinLine (12, permUp);
      break;
    case 4:
      spinLine (12, permDown);
      break;
    case 5:
      spinLine (24, permUp);
      break;
    case 6:
      spinLine (24, permDown);
      break;
    case 7:
      spinLine (36, permUp);
      break;
    case 8:
      spinLine (36, permDown);
      break;
    case 9:
      spinLine (48, permUp);
      break;
    case 10:
      spinLine (48, permDown);
      break;
    case 11:
      spinLine (60, permUp);
      break;
    case 12:
      spinLine (60, permDown);
      break;
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
  move(12);
  print();
}
