#include <stddef.h>
#pragma force_active on

extern "C" void* fn_123_3C58(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_123_3BFC(void* p, short flags) {
    if (p != NULL) {
        fn_123_3C58(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
