#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_37D3C(void* p, s32 n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_CB998(void* p, s32 n) {
    if (p) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 5);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
