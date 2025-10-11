# TUC - Time Ur Code

A simple, single-header C timer library for measuring elapsed time with nanosecond precision.

## Features
- **Single-header library** - Just include and use  
- **Nanosecond precision** - Uses POSIX clock_gettime()  
- **Zero dependencies** - Only standard C library  
- **Simple API** - `tuc_create()`, `tuc_start()`, `tuc_end()`, `tuc_result()`, `tuc_destroy()`. 

## Usage

The library is provided in **two formats**: an STB-style single-header implementation, and a fully header-only static inline version. Both provide the same API and functionality, so you can choose the style that best fits your project.

#### STB-style single-header implementation

Include the header normally in most files, but **define `TUC_IMPLEMENTATION` in one `.c` file** to compile the implementation.

```c
// In one .c file
#define TUC_IMPLEMENTATION
#include "tuc_impl.h"

// in other ones
#include "tuc_impl.h"
```

#### Static inline, fully header-only version

```c
// Include the header wherever you need to use the timer
#include "tuc_static.h"
```

## Compilation

This library requires POSIX features. Compile with the following flag:
```bash
gcc -D_POSIX_C_SOURCE=199309L -o myprogram myprogram.c
```

### Example Usage

```c
int main(void) {
    TucTimer timer = tuc_create();
    if (!timer) return 1;

    tuc_start(timer);
    // ... do work ...
    tuc_end(timer);

    printf("Elapsed: %.6f seconds\n", tuc_result(timer));
    tuc_destroy(timer);
    return 0;
}
```

## License

[MIT](https://choosealicense.com/licenses/mit/)
