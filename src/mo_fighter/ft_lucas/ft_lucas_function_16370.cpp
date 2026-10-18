#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_16370(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
