#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_49C0(void* object, s16 flag) {
    if (object != 0 && flag > 0) {
        __dl__FPv(object);
    }
    return object;
}
