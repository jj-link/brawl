#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_95_4978(void* p, short n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
