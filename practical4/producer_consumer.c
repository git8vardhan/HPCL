#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<time.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0, out = 0;

void producer() {
    int item;
    #pragma omp critical
    {
        if (count < BUFFER_SIZE) {
            item = rand() % 100; // Produces a random item
            buffer[in] = item;
            in = (in + 1) % BUFFER_SIZE;
            count++;
            printf("Produced: %d\n", item);
        } else {
            printf("Buffer is full! Can't produce more...\n");
        }
    }
}

void consumer() {
    int item;
    #pragma omp critical
    {
        if (count > 0) {
            item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            count--;
            printf("Consumed: %d\n", item);
        } else {
            printf("Buffer is empty! Can't consume anything...\n");
        }
    }
}

int main() {
    int n_producers = 4, n_consumers = 4;
    
    #pragma omp parallel num_threads(n_producers + n_consumers)
    {
        int id = omp_get_thread_num();
        
        if (id < n_producers) {
            for (int i = 0; i < 10; i++) {
                producer();
            }
        } else {
            for (int i = 0; i < 10; i++) {
                consumer();
            }
        }
    }

    return 0;
}
