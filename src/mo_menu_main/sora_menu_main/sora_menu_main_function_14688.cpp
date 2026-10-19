#include <types.h>
#pragma force_active on

extern "C" {
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_2_14688(void* arr, int flag) {
    if (arr) {
        if (arr) {
            __destroy_arr((char*)arr + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flag > 0) {
            __dl__FPv(arr);
        }
    }
    return arr;
}
