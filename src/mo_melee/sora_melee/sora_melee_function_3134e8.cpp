#include <types.h>
#pragma force_active on

extern "C" void fn_27_3135A8(void* p, s32 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_3134E8(void* p, s32 n) {
    if (p) {
        if ((u32)p + 4 != 0) {
            fn_27_3135A8((char*)p + 0xc, -1);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
