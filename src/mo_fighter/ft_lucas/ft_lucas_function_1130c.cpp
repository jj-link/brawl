#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1130C(void* object, s16 flag) {
    if (object != 0 && flag > 0) {
        operator delete(object);
    }
    return object;
}
