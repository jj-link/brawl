#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_3E4C(void* p, short n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
