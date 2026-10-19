#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_27_2905A8(void* p, s32 flag) {
    if (p != nullptr && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
