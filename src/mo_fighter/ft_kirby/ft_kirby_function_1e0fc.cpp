#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_96_1E0FC(void* p, short flag) {
    if (p != NULL && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
