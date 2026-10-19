#include <st/module.h>
#pragma force_active on

extern "C" {
extern void* fn_27_37D3C(void* p, s32 n);
extern void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern void __dl__FPv(void*);
}

extern "C" void* fn_50_5BB4(void* p, s32 n) {
    if (p != 0) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
