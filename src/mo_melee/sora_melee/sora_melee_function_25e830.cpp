#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_25EBB8(void* p, s32 n);

extern "C" void* fn_27_25E830(void* p, s32 n) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 8, (void (*)(void*, int))fn_27_25EBB8, 0xc, 0x20);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
