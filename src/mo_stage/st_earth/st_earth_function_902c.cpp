#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
}

extern "C" void* fn_66_902C(void* p, int n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
