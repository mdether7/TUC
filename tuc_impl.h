/*
 * TUC - Time Ur Code
 * A simple, single-header timer library for measuring elapsed time.
 *
 * USAGE:
 *   Include this header normally to get declarations:
 *     #include "tuc_impl.h"
 *
 *   In ONE translation unit, define TUC_IMPLEMENTATION before including:
 *     #define TUC_IMPLEMENTATION
 *     #include "tuc_impl.h"
 *
 * EXAMPLE:
 *   #include "tuc_impl.h"
 *
 *   int main(void) {
 *       TucTimer timer = tuc_create();
 *       if (!timer) return 1;
 *
 *       tuc_start(timer);
 *       // ... do work ...
 *       tuc_end(timer);
 *
 *       printf("Elapsed: %.6f seconds\n", tuc_result(timer));
 *       tuc_destroy(timer);
 *       return 0;
 *   }
 */

/*
 * MIT License
 *
 * Copyright (c) 2025 mdether7
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TUC_TIME_UR_CODE_H
#define TUC_TIME_UR_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

#define _POSIX_C_SOURCE 200809L
#include <time.h>
#include <stdlib.h>

#define TUC_ELAPSED_ERROR -1.0

typedef struct TimerInternal* TucTimer;

TucTimer tuc_create(void);
void     tuc_destroy(TucTimer timer);
void     tuc_start(TucTimer timer);
void     tuc_end(TucTimer timer);
double   tuc_result(TucTimer timer);

#ifdef TUC_IMPLEMENTATION

struct TimerInternal {
    struct timespec start;
    struct timespec end;
};

TucTimer
tuc_create(void)
{
    TucTimer timer = (TucTimer)malloc(sizeof(*timer));
    if (!timer) 
        return NULL;

    return timer;
}

void
tuc_destroy(TucTimer timer)
{
    if (!timer)
        return;

    free(timer);
}

void 
tuc_start(TucTimer timer)
{
    if (!timer)
        return;

    clock_gettime(CLOCK_MONOTONIC, &timer->start);
}

void 
tuc_end(TucTimer timer)
{
    if (!timer)
        return;

    clock_gettime(CLOCK_MONOTONIC, &timer->end);
}

double 
tuc_result(TucTimer timer)
{
    if (!timer)
        return TUC_ELAPSED_ERROR;

    return (timer->end.tv_sec - timer->start.tv_sec) +
           (timer->end.tv_nsec - timer->start.tv_nsec) / 1e9;
}

#endif /* TUC_IMPLEMENTATION */

#ifdef __cplusplus
}
#endif

#endif /* TUC_TIME_UR_CODE_H */