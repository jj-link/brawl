#include <types.h>
#pragma force_active on

extern "C" void* fn_1_139A0(void* p, s32 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_1_1BC2C(void* p, s32 n) {
    if (p) {
        fn_1_139A0(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
