#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2B1868(void* a, s32 b) {
    if (a != nullptr && b > 0)
        __dl__FPv(a);
    return a;
}
