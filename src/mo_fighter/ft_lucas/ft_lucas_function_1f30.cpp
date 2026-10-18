#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1F30(void* p, s16 flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
