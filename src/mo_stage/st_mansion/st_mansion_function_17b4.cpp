#include <stddef.h>
#pragma force_active on

extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_47_17B4(void* p, int n) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
