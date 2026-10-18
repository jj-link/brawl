#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_93_12A74(void* p, short n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
