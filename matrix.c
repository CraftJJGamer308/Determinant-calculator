// Craft JJ Industries
// Determinant Calculator
// Created on: 12 FEB 2024

#include <stdio.h>
#include <stdlib.h>

int isEven(int i) { return i % 2 == 0 ? 1 : -1; }

int det(int **a, int n) {
  int s = 0, i, j, k;

  // reserve space for (n-1)*(n-1) minor matrix
  int **a1 = malloc((n - 1) * sizeof(int *));

  // (n-1)*int matrix for each column
  for (i = 0; i < n - 1; i++) {
    a1[i] = malloc((n - 1) * sizeof(int));
  }

  // recursion break condition
  if (n == 1) {
    return a[0][0];
  }

  // recursion using Laplace-Algorithm
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      for (k = 0; k < n - 1; k++) {
        a1[j][k] = a[j + 1][k + (k >= i)];
      }
    }
    s += isEven(i) * a[0][i] * det(a1, n - 1);
  }

  // free used memory
  for (i = 0; i < n - 1; i++) {
    free(a1[i]);
  }
  free(a1);

  // return result
  return s;
}

int main() {
  int n, i, j;
  printf("Matrixgröße eingeben: ");
  scanf("%d", &n);

  // reserve space for n*n matrix
  int **a = malloc(n * sizeof(int *));

  // n*int for each column
  for (i = 0; i < n; i++) {
    a[i] = malloc(n * sizeof(int));
  }

  // input
  for (i = 0; i < n; i++) {
    printf("Zeile %d: ", i + 1);
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // print matrix
  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j < n; j++) {
      printf("%5d", a[i][j]);
    }
  }

  // print result
  printf("\n\nDeterminante: %d\n", det(a, n));
}
