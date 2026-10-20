#include <stddef.h>
#pragma force_active on

extern "C" void* fn_102_1DCC(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_1D70(void* p, short flag) {
    if (p != NULL) {
        fn_102_1DCC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
