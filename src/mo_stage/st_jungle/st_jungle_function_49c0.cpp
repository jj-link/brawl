#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_51_49C0(void* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
