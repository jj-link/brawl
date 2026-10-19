#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);

void* fn_27_3A5988(void* p, s32 n);
}

void* fn_27_3A5988(void* p, s32 n) {
    if (p != nullptr && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
