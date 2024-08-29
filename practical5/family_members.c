#include <stdio.h>
#include <omp.h>

int main() {
    const char *family_members[] = {
        "Vardhan",
        "Swanand",
        "Vivek",
        "Priya",
        "Vikram",
        "Vanita",
        "Pramila"
    };
    
    int num_family_members = sizeof(family_members) / sizeof(family_members[0]);
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        
        if (thread_id < num_family_members) {
            printf("Thread %d: %s\n", thread_id, family_members[thread_id]);
        }
    }

    return 0;
}
