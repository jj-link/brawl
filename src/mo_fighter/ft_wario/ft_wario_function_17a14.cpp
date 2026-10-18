#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);

void* fn_110_17A14(void* p, short n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
