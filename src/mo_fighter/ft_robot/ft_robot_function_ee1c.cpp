#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_EE1C(void* p, short size) {
    if (p != NULL && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
