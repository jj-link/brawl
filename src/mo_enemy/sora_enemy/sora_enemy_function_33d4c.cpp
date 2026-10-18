#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_41_33D4C(void* p, s16 n) {
    if (p != nullptr && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
