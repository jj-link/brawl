#include <types.h>
#pragma force_active on

extern "C" void fn_27_3797E8(void*, int);
extern "C" void fn_27_37A2D0(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37955C(s32 a, s32 b) {
    if (a) {
        if (a + 8 != 0 && a + 8 != 0) {
            if (a + 0x2088 != 0 && a + 0x2090 != 0) {
                fn_27_3797E8((void*)(a + 0x2094), -1);
            }
            if (a + 8 != 0 && a + 8 != 0 && a + 0x0C != 0 && a + 0x14 != 0) {
                fn_27_37A2D0((void*)(a + 0x18), -1);
            }
        }
        if (b > 0) {
            __dl__FPv((void*)a);
        }
    }
    return (void*)a;
}
