#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84358(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void* (*dtor)(void*, s32), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_292024(void* p, s32 n) {
    if (p != nullptr) {
        __destroy_arr((void*)((char*)p + 0xc), fn_27_84358, (unsigned long)0xc, (unsigned long)0x2);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
