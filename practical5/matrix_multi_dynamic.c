#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 512

void matrix_multiply_dynamic(double A[N][N], double B[N][N], double C[N][N]) {
    #pragma omp parallel for schedule(dynamic)
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

    
    double start = omp_get_wtime();
    matrix_multiply_dynamic(A, B, C);
    double end = omp_get_wtime();
    double time_taken = end - start;

    printf("Dynamic Scheduling Execution Time: %f seconds\n", time_taken);

    return 0;
}
