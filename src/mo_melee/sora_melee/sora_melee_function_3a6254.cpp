#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3A6254(void* p, s32 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
