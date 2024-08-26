#include <stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>


int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to compare two integers for descending order
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    printf("\nEnter the number of elements in both vectors: ");
    scanf("%d", &n);

    int A[n], B[n];
    
    srand(time(0));
    
    printf("Array A is:\n");
    for(int i=0;i<n;i++){
        A[i] = rand() % 51;
        printf("%d ", A[i]);
    }

    printf("\n\n");

    printf("Array B is:\n");
    for(int i=0;i<n;i++){
        B[i] = rand() % 51;
        printf("%d ", B[i]);
    }

    printf("\n");

    qsort(A,n,sizeof(int),compare_asc);
    qsort(B,n,sizeof(int),compare_desc);

    int min_dot_product = 0;

    #pragma omp parallel for reduction(+:min_dot_product)
      for(int i=0;i<n;i++){
        min_dot_product += A[i] * B[i];
      }

    printf("\nMinimum Dot product of both vectors is: %d\n",min_dot_product);


    // Your code here
    return 0;
}