#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_56_5A10(void* p, int flags) {
    if (p != NULL && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
