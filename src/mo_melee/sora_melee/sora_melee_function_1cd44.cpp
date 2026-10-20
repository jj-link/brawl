#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_6610(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void* p);

void* fn_27_1CD44(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_6610, 0x10, 4);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
