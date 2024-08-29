#include<stdio.h>
#include<omp.h>

int main()
{
    int sum =0;

    #pragma omp parallel reduction(+:sum)
    {
        int id = omp_get_thread_num();
        int sz = omp_get_num_threads();

        int sq = id*id;
        sum += sq;

        printf("Thread id is : %d and its square is : %d\n", id, sq);
    }

    printf("Total Sum : %d\n", sum);
}