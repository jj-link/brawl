#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);

void* fn_27_37790C(void* p, s32 n) {
    if (p != nullptr && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
