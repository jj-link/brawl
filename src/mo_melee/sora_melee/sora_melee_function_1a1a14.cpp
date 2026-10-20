#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_AB510(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_1A1A14(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_AB510, 0x10, 0x12);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
