#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_15274(void* p, s16 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
