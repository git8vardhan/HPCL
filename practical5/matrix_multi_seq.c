#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 512

void matrix_multiply_serial(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    double A[N][N], B[N][N], C[N][N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    clock_t start = clock();
    matrix_multiply_serial(A, B, C);
    clock_t end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    
    printf("Sequential execution took a time of: %f seconds\n", time_taken);

    return 0;
}
