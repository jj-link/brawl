#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void* (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_2C2490(void*, int);

void* fn_27_2C1D3C(void* p, int n) {
    if (p != 0) {
        __destroy_arr((void*)((char*)p + 8), fn_27_2C2490, 0xcUL, 0x40UL);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
