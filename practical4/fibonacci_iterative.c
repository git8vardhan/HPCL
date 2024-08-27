#include <omp.h>
#include <stdio.h>
#include<time.h>

int main() {
    int n = 20; // Compute the first 20 Fibonacci numbers
    long long fib[n];

    fib[0] = 0;
    fib[1] = 1;

    // Parallelize the loop

    float start = omp_get_wtime();

    // #pragma omp parallel for - PARALLEL PROCESSING HERE WILL CAUSE A PROBLEM AND WILL GIVE INCORRECT RESULTS
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    float end = omp_get_wtime();

    // Print the Fibonacci numbers
    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    printf("Time taken for the exectution: %f seconds\n", end - start);

    return 0;
}
