#include <stddef.h>
#pragma force_active on

extern "C" void* fn_93_285C(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_12B10(void* a, short b) {
    if (a != NULL) {
        fn_93_285C(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
