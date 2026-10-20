#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_1A3F58(void* ptr, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_119_3940(void* p, short n) {
    if (p != NULL) {
        fn_27_1A3F58(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
