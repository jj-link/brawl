#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_2AE068(void*, int);

extern "C" void* fn_27_2AC2D8(void* p, s32 n) {
    if (p != 0) {
        __destroy_arr((char*)p + 8, fn_27_2AE068, 0xC, 3);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
