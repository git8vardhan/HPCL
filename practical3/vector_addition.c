#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 200

void vector_scalar_addition(int *a, int scalar, int n, char *schedule, int chunk_size, int dynamic) {
    int i;
    double start_time, end_time;

    start_time = omp_get_wtime();

    if (dynamic) {
        #pragma omp parallel for schedule(dynamic, chunk_size)
        for (i = 0; i < n; i++) {
            a[i] += scalar;
        }
    } 
    
    else {
        #pragma omp parallel for schedule(static, chunk_size)
        for (i = 0; i < n; i++) {
            a[i] += scalar;
        }
    }

    end_time = omp_get_wtime();
    printf("%s Schedule with chunk size %d took %f seconds.\n\n", schedule, chunk_size, end_time - start_time);
}

int main() {
    int i;
    int *a = (int *)malloc(VECTOR_SIZE * sizeof(int));
    int scalar = 5;
    int chunk_sizes[] = {1, 5, 10, 20};

    // Initialize the vector
    for (i = 0; i < VECTOR_SIZE; i++) {
        a[i] = i;
    }

    // Static Schedule
    for (i = 0; i < 4; i++) {
        vector_scalar_addition(a, scalar, VECTOR_SIZE, "Static", chunk_sizes[i], 0);
    }

    // Dynamic Schedule
    for (i = 0; i < 4; i++) {
        vector_scalar_addition(a, scalar, VECTOR_SIZE, "Dynamic", chunk_sizes[i], 1);
    }

    // Demonstration of nowait
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (i = 0; i < VECTOR_SIZE; i++) {
            a[i] += scalar;
        }
    }

    free(a);
    return 0;
}
