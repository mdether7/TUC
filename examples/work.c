#include <stdlib.h>

void memory_work(size_t alloc_count) 
{
    for (size_t i = 0; i < alloc_count; i++) {
        int *arr = malloc(1024 * sizeof(int));
        if (arr) 
            free(arr);
    }
}