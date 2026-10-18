#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_12768(void* p, s16 flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
