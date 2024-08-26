#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vector_scalar_addition(int *arr, int scalar, long int size) {
    for (long int i = 0; i < size; i++) {
        arr[i] += scalar;  // Adding scalar
    }
}

int main() {
    int scalar;
    printf("Enter the value of the scalar: ");
    scanf("%d", &scalar);
    printf("\n");

    int data_size[5];
    
    srand(time(0));

    // Generate random data sizes
    for (int i = 0; i < 5; i++) {
        data_size[i] = (rand() % 1000000) + 1000;
    }

    // Loop over different data sizes
    for (int i = 0; i < 5; i++) {
        long int size = data_size[i];

        int *arr = (int *)malloc(size * sizeof(int));

        // Initialize the array
        for (long int j = 0; j < size; j++) {
            arr[j] = j;
        }

        printf("\nData Size: %ld\n", size);

        float start = clock() / (float)CLOCKS_PER_SEC;

        vector_scalar_addition(arr, scalar, size);

        float end = clock() / (float)CLOCKS_PER_SEC;

        printf("Time taken: %f s\n", end - start);
        printf("---------------------------------------------------------\n");

        free(arr);
    }

    return 0;
}
