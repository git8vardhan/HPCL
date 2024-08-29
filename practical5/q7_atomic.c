#include <stdio.h>
#include <omp.h>

#define SIZE 1000000
int main() {
    int array[SIZE];
    long long total_sum = 0;
    for (int i = 0; i < SIZE; i++) {
        array[i] = i+1; 
    }
    double start_time = omp_get_wtime();
    omp_set_num_threads(6);
    #pragma omp parallel
    {
        long long temp =0;
        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            // #pragma omp atomic
            temp += array[i];
        }

        #pragma omp critical
        {
            total_sum += temp;
        }
    }

    double end_time = omp_get_wtime();
    printf("Parallely calculated total Sum using critical section: %lld\n", total_sum);
    printf("Execution time taken: %f seconds\n", end_time - start_time);

    return 0;
}
