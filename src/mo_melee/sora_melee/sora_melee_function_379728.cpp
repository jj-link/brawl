#include <types.h>
#pragma force_active on

extern "C" void fn_27_3797E8(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_379728(s32 a, s32 b) {
    if (a) {
        if (a + 8 != 0) {
            fn_27_3797E8((void*)(a + 0xC), -1);
        }
        if (b > 0) {
            __dl__FPv((void*)a);
        }
    }
    return (void*)a;
}