#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_152F4(void* object, s16 flags) {
    if (object != 0 && flags > 0) {
        __dl__FPv(object);
    }
    return object;
}
