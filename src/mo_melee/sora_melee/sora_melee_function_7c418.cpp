#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7C418(void* arg1, s32 arg2) {
    if (arg1 != 0 && arg2 > 0) {
        __dl__FPv(arg1);
    }
    return arg1;
}
