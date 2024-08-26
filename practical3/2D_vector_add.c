#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void matrix_addition(int size, int num_threads) {
    // Allocate memory for matrices dynamically
    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    // Measure time
    double start = omp_get_wtime();

    // Parallel matrix addition using OpenMP
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    double end = omp_get_wtime();
    printf("Matrix size: %d x %d\n", size, size);
    printf("Threads: %d\n", num_threads);
    printf("Time taken: %f seconds\n", end - start);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main() {
    int sizes[] = {250, 500, 750, 1000, 2000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int thread_counts[] = {1, 2, 4, 8};
    int num_threads = sizeof(thread_counts) / sizeof(thread_counts[0]);

    // Run matrix addition for different sizes and number of threads
    for (int i = 0; i < num_sizes; i++) {
        for (int j = 0; j < num_threads; j++) {
            matrix_addition(sizes[i], thread_counts[j]);
        }
    }

    return 0;
}
