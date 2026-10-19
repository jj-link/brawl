#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_168A40(void* p, s32 n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
