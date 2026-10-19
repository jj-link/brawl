#include <stddef.h>
#pragma force_active on

extern "C" void* fn_122_3820(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_3958(void* p, short flag) {
    if (p != NULL) {
        fn_122_3820(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
