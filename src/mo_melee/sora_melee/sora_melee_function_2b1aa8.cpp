#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2B1AA8(void* obj, s32 flag) {
    if (obj && flag > 0)
        __dl__FPv(obj);
    return obj;
}
