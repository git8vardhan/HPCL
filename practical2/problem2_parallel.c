#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

double calculatePi(long long int points)
{
    long long inner_points = 0;

    unsigned int seed = time(0);

#pragma omp parallel
    {
        unsigned int local_seed = seed + omp_get_thread_num();
        long long thread_inner_points = 0;

#pragma omp for
        for (int i = 0; i < points; i++)
        {
            double x = (double)rand_r(&local_seed) / RAND_MAX;
            double y = (double)rand_r(&local_seed) / RAND_MAX;

            if (x * x + y * y <= 1.0)
            {
                thread_inner_points++;
            }
        }

#pragma omp atomic
        inner_points += thread_inner_points;
    }

    return 4.0 * inner_points / points;
}
int main()
{
    long long int points = 100000000;
    double pi;

    float start = omp_get_wtime();

    pi = calculatePi(points);

    float end = omp_get_wtime();

    printf("\nThe value of pi calculated using parallel processing is: %lf\n", pi);
    printf("\nExecution time was: %f\n", end - start); 
    // Your code here
    return 0;
}