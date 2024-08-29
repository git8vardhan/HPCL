#include <stdio.h>
#include <omp.h>

int main() {
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
       
        #pragma omp critical
        {
            if (thread_id == 0) {
                
                for (int i = 1; i <= 10; ++i) {  
                    printf("Thread %d: %d\n", thread_id, 2*i);
                }
            } else if (thread_id == 1) {
                
                
                for (int i = 1; i <= 10; ++i) {  
                    printf("Thread %d: %d\n", thread_id, 4*i);
                }
            }
        }

        
    }

    return 0;
}
