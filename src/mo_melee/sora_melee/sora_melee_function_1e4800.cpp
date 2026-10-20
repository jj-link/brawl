#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_845D8(void*, int);

extern "C" void* fn_27_1E4800(void* arr, int count) {
    if (arr) {
        __destroy_arr((char*)arr + 0xc, fn_27_845D8, 0xc, 1);
        if (count > 0)
            __dl__FPv(arr);
    }
    return arr;
}
