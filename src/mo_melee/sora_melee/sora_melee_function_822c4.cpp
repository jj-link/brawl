#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);
void* fn_27_822C4(void* p, s32 flag);
}

void* fn_27_822C4(void* p, s32 flag) {
    if (p != nullptr && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
