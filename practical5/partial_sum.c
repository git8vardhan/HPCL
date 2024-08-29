#include <stdio.h>
#include <omp.h>

int main()
{
    int n = 20;      
    int total_sum = 0;   
    int partial_sum = 0; 

    omp_set_num_threads(4);

#pragma omp parallel private(partial_sum) reduction(+:total_sum)
    {
        // Initialize partial_sum to 0 for each thread
        partial_sum = 0;

        // Get the thread ID and the total number of threads
        int thread_id = omp_get_thread_num();

        int num_threads = omp_get_num_threads();

        // Calculate the range for each thread
        int chunk_size = n / num_threads;
        int start = thread_id * chunk_size + 1;
        int end = (thread_id == num_threads - 1) ? n : start + chunk_size - 1;

        // Compute the partial sum for the range of numbers assigned to this thread
        for (int i = start; i <= end; ++i)
        {
            partial_sum += i;
        }

        total_sum += partial_sum;
        // Print partial sum from each thread
        printf("Thread %d: Partial sum from %d to %d = %d\n", thread_id, start, end, partial_sum);

        // Use the lastprivate clause to ensure that the final value of partial_sum is captured
    }

    // #pragma omp single
    // {
    //     total_sum = partial_sum;
    // }

    // Print the final total sum
    printf("Total sum of the first %d natural numbers = %d\n", n, total_sum);

    return 0;
}
