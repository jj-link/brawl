#include <types.h>
#pragma force_active on

extern "C" void* fn_114_10C40(void* object, s16 flag) {
    if (object != 0 && flag > 0) {
        operator delete(object);
    }
    return object;
}
