#include <stdio.h>
#include <omp.h>

//Problem Statement 2

int main()
{
    int numThreads;
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

    printf("Sequential Execution: \n");

    double start = omp_get_wtime();

    for (int i = 0; i < numThreads; i++)
    {
        // Note: OpenMP's omp_get_thread_num() is only valid within parallel regions
        printf("Sequential!--> Hello, World!! %d\n", 0);
    }

    double end = omp_get_wtime();

    double seq = end - start;

    printf("\nParallel Execution: \n");
    omp_set_num_threads(numThreads);

    start = omp_get_wtime();

#pragma omp parallel
    {
        printf("Parallel! --> Hello, World! %d\n", omp_get_thread_num());
    }

    end = omp_get_wtime();

    double para = end - start;

    printf("Execution time for Sequential Processing: %f\n", seq);
    printf("Execution time for Parallel Processing: %f\n", para);

    return 0;
}
