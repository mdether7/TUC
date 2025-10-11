#include <stdio.h>

#define TUC_IMPLEMENTATION
#include "../tuc_impl.h"

int main(void) 
{
    TucTimer timer = tuc_create();
    if (!timer) 
        return 1;

    tuc_start(timer);
    // ... do work ...
    tuc_end(timer);

    printf("Elapsed: %.6f seconds\n", tuc_result(timer));
    tuc_destroy(timer);
    return 0;
}