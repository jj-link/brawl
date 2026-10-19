#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2B10A8(void* p, s32 n) {
    if (p != nullptr) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
