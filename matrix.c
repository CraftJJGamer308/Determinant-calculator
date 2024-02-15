// Craft JJ Industries
// Determinant Calculator
// Created on: 15 FEB 2024

#include <stdio.h>
#include <stdlib.h>
#define PRINT_BAR (printf("\n-----------------------------\n"))

float isEven(int i) { return i % 2 == 0 ? 1. : -1.; }

float det(float **a, int n) {
  // recursion break condition
  if (n == 1) {
    return a[0][0];
  }

  int i, j, k;
  float s = 0;

  // reserve space for (n-1)*(n-1) minor matrix
  float **a1 = malloc((n - 1) * sizeof(float *));

  // (n-1)*int for each column
  for (i = 0; i < n - 1; i++) {
    a1[i] = malloc((n - 1) * sizeof(float));
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
  printf("Craft JJ Industries, "
         "2024\nMatrix-Determinante-Rechner");
  PRINT_BAR;

  printf("Matrixgröße eingeben: ");
  scanf("%d", &n);

  // reserve space for n*n matrix
  float **a = malloc(n * sizeof(float *));

  // n*int for each column
  for (i = 0; i < n; i++) {
    a[i] = malloc(n * sizeof(float));
  }

  // input
  for (i = 0; i < n; i++) {
    printf("Zeile %d: ", i + 1);
    for (j = 0; j < n; j++) {
      scanf("%f", &a[i][j]);
    }
  }

  // print matrix
  PRINT_BAR;
  printf("eingegebene Matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%7.2f", a[i][j]);
    }
    printf("\n");
  }

  // print result
  PRINT_BAR;
  printf("Determinante: %f\n", det(a, n));
}
