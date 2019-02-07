#include <stdio.h>
#include <math.h>

// Write a program that will generate a multiplication
// table NxM where N and M are provided by the user. The
// multiplication table must be formatted such that all
// the numbers are aligned properly.

int cols;

int displayArray(int a[][cols], int rows, int col) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < col; j++) {
      printf("%2i ", a[i][j]);
    }
    printf("\n");
  }
}


int main(void) {
  
  int nValue, mValue = 0;

  printf("N value:");
  scanf("%i", &nValue);
  printf("M value:");
  scanf("%i", &mValue);
  cols = mValue;
  
  int values[nValue][mValue];


  for (int i = 1; i <= nValue; i++) {
    for (int j = 1; j <= mValue; j++) {
      values[i - 1][j - 1] = i * j;
    }
  }

  displayArray(values, nValue, mValue);

  return 0;
}