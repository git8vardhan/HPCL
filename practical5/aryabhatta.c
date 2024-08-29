#include<stdio.h>
#include<omp.h>

int main()
{
    int Aryabhatta = 10;

    #pragma omp parallel private(Aryabhatta)
    {
        Aryabhatta = 10;

        int id = omp_get_thread_num();
        int n = omp_get_num_threads();

        int val = id * Aryabhatta;

        printf("%d * %d = %d\n", id, Aryabhatta, val);
    }
}

