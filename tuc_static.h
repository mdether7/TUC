/*
 * TUC - Time Ur Code
 * A simple, single-header timer library for measuring elapsed time.
 *
 * USAGE:
 *   Simply include this header and use directly. All functions are inline.
 *     #include "tuc_static.h"
 *
 * EXAMPLE:
 *     #include "tuc_static.h"
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

struct TimerInternal {
    struct timespec start;
    struct timespec end;
};

typedef struct TimerInternal* TucTimer;

static inline TucTimer
tuc_create(void)
{
    TucTimer timer = NULL;

    timer = (TucTimer)malloc(sizeof(*timer));
    if (!timer) 
        return NULL;

    return timer;
}

static inline void
tuc_destroy(TucTimer timer)
{
    if (!timer)
        return;

    free(timer);
}

static inline void 
tuc_start(TucTimer timer)
{
    if (!timer)
        return;

    clock_gettime(CLOCK_MONOTONIC, &timer->start);
}

static inline void 
tuc_end(TucTimer timer)
{
    if (!timer)
        return;

    clock_gettime(CLOCK_MONOTONIC, &timer->end);
}

static inline double 
tuc_result(TucTimer timer)
{
    if (!timer)
        return 0.0;

    return (timer->end.tv_sec - timer->start.tv_sec) +
           (timer->end.tv_nsec - timer->start.tv_nsec) / 1e9;
}

#ifdef __cplusplus
}
#endif

#endif /* TUC_TIME_UR_CODE_H */


