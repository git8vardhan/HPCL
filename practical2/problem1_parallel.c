#include <stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void vector_scalar_addition(int *arr,int scalar,long int size, int numThreads){
      omp_set_num_threads(numThreads);

      #pragma omp parallel for
      for(int i=0;i<size;i++){
         arr[i] += scalar;  // Adding scalar
      }
}

int main() {
    // long int size = 1000000;
    int scalar;
    printf("Enter the value of the scalar: ");
    scanf("%d",&scalar);
    printf("\n");

    int numThreads[] = {1,2,4,8,16};
    int data_size[5];

    srand(time(0));

    for(int i=0;i<5;i++){
        data_size[i] = (rand() % 1000000) + 1000;
    }

    for(int i=0;i<5;i++){
        long int size = data_size[i];

        int *arr = (int*)malloc(size*sizeof(int));

        for(int j=0;j<size;j++){
            arr[j] = j;
        }

        printf("\nData Size: %ld\n", size);

        for(int i=0;i<5;i++){
            printf("Number of threads: %d\n", numThreads[i]);

            float start = omp_get_wtime();

            vector_scalar_addition(arr, scalar, size, numThreads[i]);

            float end = omp_get_wtime();

            printf("Time taken: %f s\n\n", end - start);
            printf("---------------------------------------------------------\n");

        }

        free(arr);
    }
       
    // Your code here
    return 0;
}