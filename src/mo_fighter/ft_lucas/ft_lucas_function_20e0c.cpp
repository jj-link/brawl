#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_20E0C(void* p, s16 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
