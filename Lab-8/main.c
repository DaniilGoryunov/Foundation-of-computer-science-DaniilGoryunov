#include <stdio.h>
#include <string.h>

#define N (2)

typedef unsigned uint;

void matrixMultiplication(int right[N][N], int left[N][N]);

int fibo(uint k) {
    int matrix[N][N] = { 1, 1, 1, 0 };
    int result[N][N] = { 1, 1, 1, 0 };
    while (--k != 0) {
        matrixMultiplication(result, matrix);
    }
    return result[0][1];
}

void matrixMultiplication(int right[N][N], int left[N][N]) {
    int matrix[N][N] = { { 0 } };
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            for (size_t k = 0; k < N; ++k)
                matrix[i][j] += right[i][k] * left[k][j];
    memcpy(right, matrix, N * N * sizeof matrix[0][0]);
}

int main(){
    uint k;
    scanf("%d", &k);
    printf("%d\n", fibo(k));
    return 0;
}
/*
 
 int matrix[2][2],matrixxx[2][2],matrixx[2][2];
 matrixxx[0][0]=1;
 matrixxx[1][0]=1;
 matrixxx[1][0]=1;
 matrixxx[0][1]=1;
 matrixxx[1][1]=0;
 matrixx[0][0]=1;
 matrixx[1][0]=1;
 matrixx[0][1]=1;
 matrixx[1][1]=0;
 for (int i=3;i<exp;i++){
     matrix[0][0]=(matrixxx[0][0]*matrixx[0][0]+matrixxx[1][0]*matrixx[0][1]);
     matrix[0][1]=(matrixxx[0][0]*matrixx[0][1]+matrixxx[0][1]*matrixx[1][1]);
     matrix[1][0]=(matrixxx[1][0]*matrixx[0][0]+matrixxx[1][1]*matrixx[1][0]);
     matrix[1][1]=(matrixxx[1][0]*matrixx[0][1]+matrixxx[1][1]*matrixx[1][1]);
     matrixxx[0][0]=matrix[0][0];
     matrixxx[1][0]=matrix[1][0];
     matrixxx[0][1]=matrix[0][1];
     matrixxx[1][1]=matrix[1][1];
 }
 printf("%d\n",matrix[0][0]);

 */
