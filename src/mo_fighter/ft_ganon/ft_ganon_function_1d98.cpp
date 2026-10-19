#include <stddef.h>
#pragma force_active on

extern "C" void* fn_109_1DF4(void* ptr, short count);

extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_109_1D98(void* p, short flag) {
    if (p != NULL) {
        fn_109_1DF4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
