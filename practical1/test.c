#include <stdio.h>
#include <omp.h>

int main()
{
    double start_time = omp_get_wtime();
#pragma omp parallel

    {
        printf("Hello, world!!\n");
    }

    double end_time = omp_get_wtime();
    printf("Time taken by the parallel region: %f seconds\n", end_time - start_time);

    return 0;
}
