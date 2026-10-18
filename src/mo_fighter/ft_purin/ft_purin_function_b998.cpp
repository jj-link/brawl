#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_B998(void* p, s16 size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
