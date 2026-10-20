#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), u32, u32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_86D4C(void*, int);

extern "C" void* fn_27_291A58(void* p, s32 flag) {
    if (p) {
        __destroy_arr((u8*)p + 0xC, fn_27_86D4C, 0xA0, 3);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
