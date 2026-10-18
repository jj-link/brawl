#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_95_13944(void* p, short flag) {
    if (p != NULL && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
