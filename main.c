#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (7)

void diag(int d, int n, int (*matrix)[n]);

int main() {
  int n;
  scanf("%d", &n);
  int matrix[MAX_N * MAX_N];
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrix[i * n + j]);
    }
  }
  for (int d = 1; d < n*2; d++) {
    diag(d, n, (int (*)[n]) matrix);
  }
  printf("\n");
  return 0;
}

void diag(int d, int n, int (*matrix)[n]) {
    int i, j, k;
    int t = 1;
    for (i=0; i < n; i++) {
        for (j = 0, k = i; j < i+1 ; j++, k--) {
            if (t == d) printf("%d ", matrix[k][j]);
        }
        t++;
    }
    for (j = 1; j <= n-1; j++) {
        for (i = n-1, k = j; k <= n-1; i--, k++) {
            if (t == d) printf("%d ", matrix[i][k]);
        }
        ++t;
    }
}


    //1 3 6 10 2 5 9 13 4 8 12 15 7 11 14 16
