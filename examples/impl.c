#include <stdio.h>

#define TUC_IMPLEMENTATION
#include "../tuc_impl.h"

#define NUMBER_OF_MALLOCS 10000

extern void memory_work(size_t alloc_count); 

int main(void) 
{
    TucTimer timer = tuc_create();
    if (!timer) 
        return 1;

    tuc_start(timer);
    memory_work(NUMBER_OF_MALLOCS);
    tuc_end(timer);

    printf("Elapsed: %.6f seconds\n", tuc_result(timer));
    tuc_destroy(timer);
    return 0;
}