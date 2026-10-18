#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_76_3B88(void* p, int n) {
    if (p != NULL) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
