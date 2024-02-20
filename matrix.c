// Craft JJ Industries
// Determinant Calculator
// Created on: 15 FEB 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_BAR (printf("\n-----------------------------\n"))

long double isEven(int i) { return i % 2 == 0 ? 1.L : -1.L; }

long double det(long double **a, int n) {
  // recursion break condition
  if (n == 1) {
    return a[0][0];
  }

  int i, j, k;
  long double s = 0;

  // reserve space for (n-1)*(n-1) minor matrix
  long double **a1 = malloc((n - 1) * sizeof(long double *));

  // (n-1)*int for each column
  for (i = 0; i < n - 1; i++) {
    a1[i] = malloc((n - 1) * sizeof(long double));
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
  int n, i, j, length_max = 0;
  char *buf = malloc(18 * sizeof(char));

  printf("Craft JJ Industries, "
         "2024\nMatrix-Determinante-Rechner");
  PRINT_BAR;

  printf("Matrixgröße eingeben: ");
  scanf("%d", &n);

  // reserve space for n*n matrix
  long double **a = malloc(n * sizeof(long double *));

  // n*int for each column
  for (i = 0; i < n; i++) {
    a[i] = malloc(n * sizeof(long double));
  }

  // input
  for (i = 0; i < n; i++) {
    printf("Zeile %d: ", i + 1);
    for (j = 0; j < n; j++) {
      scanf("%Lf", &a[i][j]);

      sprintf(buf, "%.17Lg", a[i][j]);
      if (length_max < strlen(buf)) {
        length_max = strlen(buf);
      }
    }
  }

  // print matrix
  PRINT_BAR;
  printf("eingegebene Matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%*.17Lg", length_max + 2, a[i][j]);
    }
    printf("\n");
  }

  // print result
  PRINT_BAR;
  printf("Determinante: %.17Lg\n", det(a, n));
}
