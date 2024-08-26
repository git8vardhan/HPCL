#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

double calculatePi(long long int points)
{
    double x, y;
    double inner_points = 0;

    for (long long int i = 0; i < points; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if ((x * x) + (y * y) <= 1.0)
        {
            inner_points++;
        }
    }

    return 4.0 * (inner_points / points);
}

int main()
{
    long long int points = 100000000;
    double pi;

    double start = clock() / CLOCKS_PER_SEC;

    pi = calculatePi(points);

    double end = clock() / CLOCKS_PER_SEC;

    printf("\nThe value of pi calculated using sequential processing is: %lf\n", pi);
    printf("Execution time was: %lfs\n", end - start);
    // Your code here
    return 0;
}