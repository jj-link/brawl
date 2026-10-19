#include <types.h>
#pragma force_active on

extern "C" void* fn_27_345BBC(void* param1, s32 param2) {
    extern void __dl__FPv(void*);
    if (param1 != nullptr && param2 > 0)
        __dl__FPv(param1);
    return param1;
}
