#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_2ADFB0(void* p, s32 n);

void* fn_27_2ACFE8(void* p, s32 n) {
    if (p != 0) {
        __destroy_arr((void*)((u8*)p + 8), (void (*)(void*, int))fn_27_2ADFB0, 0xc, 0x40);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
