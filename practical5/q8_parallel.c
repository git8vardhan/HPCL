#include <stdio.h>
#include <omp.h>

#define SIZE 1000000 

int main() {
    int array[SIZE];
    long long total_sum = 0;

    
    for (int i = 0; i < SIZE; i++) {
        array[i] = 1; 
    }

    double start_time = omp_get_wtime();

    omp_set_num_threads(6);
    #pragma omp parallel reduction(+:total_sum)
    {
        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            total_sum += array[i];
        }
    }

    double end_time = omp_get_wtime();
    double time_taken = end_time - start_time;

    printf("\nParallely calculated total sum: %lld\n", total_sum);
    printf("Execution time taken: %f seconds\n", time_taken);

    return 0;
}
