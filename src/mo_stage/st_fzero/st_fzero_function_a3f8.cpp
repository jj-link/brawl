#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_61_A3F8(void* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
