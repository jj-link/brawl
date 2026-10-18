#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_10C2C(void* p, short n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
