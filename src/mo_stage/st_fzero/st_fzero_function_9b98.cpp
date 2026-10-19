#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_37D3C(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_61_9B98(void* p, s32 n);
}

extern "C" void* fn_61_9B98(void* p, s32 n) {
    if (p != 0) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
