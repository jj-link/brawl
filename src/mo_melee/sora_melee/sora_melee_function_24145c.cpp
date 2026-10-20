#include <types.h>
#pragma force_active on

extern "C" void fn_27_23AB44(void* a, s32 b);
extern "C" void __dl__FPv(void* a);

extern "C" void* fn_27_24145C(void* a, s32 b) {
    if (a) {
        fn_27_23AB44(a, 0);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
