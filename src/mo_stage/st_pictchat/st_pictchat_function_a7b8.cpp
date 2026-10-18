#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_73_A7B8(void* p, int n) {
    if (p != NULL && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
