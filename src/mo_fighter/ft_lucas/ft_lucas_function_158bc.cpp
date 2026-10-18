#include <types.h>
#pragma force_active on

extern "C" void* fn_114_158BC(void* object, s16 flags) {
    if (object != 0 && flags > 0) {
        operator delete(object);
    }
    return object;
}
