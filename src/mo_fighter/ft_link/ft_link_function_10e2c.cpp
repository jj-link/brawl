#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_93_10E2C(void* p, short flag) {
    if (p != NULL) {
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
