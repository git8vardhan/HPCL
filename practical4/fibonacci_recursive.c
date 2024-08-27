#include <omp.h>
#include <stdio.h>
#include<time.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        long long x, y;

        #pragma omp task shared(x)
        x = fib(n - 1);

        #pragma omp task shared(y)
        y = fib(n - 2);

        #pragma omp taskwait
        return x + y;
    }
}

int main() {
    int n = 20; // Compute the 20th Fibonacci number

    long long result;

    // Parallel region to initiate tasks

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            result = fib(n);
        }
    }

    double end = omp_get_wtime();

    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Time taken: %.6f seconds\n", end - start);

    return 0;
}
















































// #include <omp.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void fib(int n, long long* fib_arr) {
//     if (n <= 1) {
//         fib_arr[n] = n;
//     } else {
//         long long x, y;

//         #pragma omp task shared(x)
//         fib(n - 1, &x);

//         #pragma omp task shared(y)
//         fib(n - 2, &y);

//         #pragma omp taskwait
//         fib_arr[n] = x + y;
//     }
// }

// int main() {
//     int n = 20; // Compute Fibonacci numbers up to the 20th
//     long long *fib_arr = (long long*)malloc((n + 1) * sizeof(long long));

//     double start = omp_get_wtime();

//     // Initialize OpenMP parallel region
//     #pragma omp parallel
//     {
//         #pragma omp single
//         {
//             fib(n, fib_arr);
//         }
//     }

//     double end = omp_get_wtime();

//     // Print the Fibonacci numbers
//     printf("Fibonacci Series up to Fibonacci(%d):\n", n);
//     for (int i = 0; i <= n; i++) {
//         printf("Fibonacci(%d) = %lld\n", i, fib_arr[i]);
//     }
//     printf("Time taken: %.6f seconds\n", end - start);

//     free(fib_arr);
//     return 0;
// }

