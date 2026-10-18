#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1A99C(void* p, short flags) {
    if (p != NULL && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
