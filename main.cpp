#include <cstdio>
#include <cstring>

char pixels[6][9]={
  {'A', 'g', 'g',
   'A', 'g', 'A',
   'A', 'g', 'g'},

  {'w', 'w', 'w',
   'w', 'w', 'w',
   'w', 'w', 'w'},

  {'b', 'b', 'b',
   'b', 'b', 'b',
   'b', 'b', 'b'},

  {'y', 'y', 'y',
   'y', 'y', 'y',
   'y', 'y', 'y'},

  {'o', 'o', 'A',
   'o', 'A', 'A',
   'o', 'o', 'A'},

  {'A', 'r', 'r',
   'A', 'A', 'r',
   'A', 'r', 'r'},
};

char* line[32];
char staticLine[12];
char lateral[9];
char k = 0;

char left[2] = {0, 4};
char right[2] = {12, 5};

char permDown[12] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
char permUp[12] = {9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8};

char face [9];

char permLateralDown[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
char permLateralUp[9] = {2, 5, 8, 1, 4, 7, 0, 3, 6};

char* up [2] = {permUp, permLateralUp};
char* down [2] = {permDown, permLateralDown};


void spinLateral (char side, char perm[9]) {
  memcpy(lateral, pixels[side], sizeof(lateral));
  for (char i = 0; i < 9; i++) {
    pixels[side][i]=lateral[perm[i]];
  }
}

void savesLine () {
  for (char i = 0; i < 4; i++) {
    for (char j = 0; j < 7; j += 3) {
      line[k] = &pixels[i][j];
      line[k+12] = &pixels[i][j+2];
      k++;
    }
  }
  k = 0;
}

void spinLine (char side, char perm[12]) {
  for (char i = 0; i < 12; i++) {
    staticLine[i] = *line[i+side];
  }
  for (char i = 0; i < 12; i++) {
    *line[i+side]=staticLine[perm[i]];
  }
}

void fullBackSpinBackSpin () {
    memcpy(face, pixels[0], sizeof(face));
    memcpy(pixels[0], pixels[1], sizeof(face));
    memcpy(pixels[1], pixels[2], sizeof(face));
    memcpy(pixels[2], pixels[3], sizeof(face));
    memcpy(pixels[3], face, sizeof(face));

    spinLateral(4, permLateralDown);
    spinLateral(5, permLateralUp);
}

void fullFrontSpin () {
    memcpy(face, pixels[3], sizeof(face));
    memcpy(pixels[3], pixels[2], sizeof(face));
    memcpy(pixels[2], pixels[1], sizeof(face));
    memcpy(pixels[1], pixels[0], sizeof(face));
    memcpy(pixels[0], face, sizeof(face)); 
    
    spinLateral(4, permLateralUp);
    spinLateral(5, permLateralDown);
}

void lr(char side[2], char* direction [2]) {
  spinLine(side[0], direction[0]);
  spinLateral(side[1], direction[1]);
}

void print () {
  for (char i = 0; i < 6; i++) {
    for (char j = 0; j < 3; j++) {
      for (char l = 0; l < 3; l++) {
        printf("%c ",pixels[i][k]);
        k++;
      }
      printf("\n");
    }
    printf("\n");
    k = 0;
  }
}

int main () {
  //avesLine();
 fullFrontSpin();
  //lr(left, down);
  print();
}
