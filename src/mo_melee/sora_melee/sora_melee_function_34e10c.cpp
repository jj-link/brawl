#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_34E10C(void* p, s32 size) {
    if (p != nullptr) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
