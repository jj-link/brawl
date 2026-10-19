#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void* fn_27_2B1828(void* r3, s32 r4) {
    if (r3 != nullptr && r4 > 0) {
        __dl__FPv(r3);
    }
    return r3;
}
}
