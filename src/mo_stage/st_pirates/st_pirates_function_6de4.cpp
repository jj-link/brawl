#include <types.h>
#pragma force_active on

extern "C" void* fn_27_37D3C(void*, s32);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_52_6DE4(void* p, s32 n) {
    if (p != nullptr) {
        __destroy_arr((u8*)p + 0xc, (void(*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
