#include <types.h>
#pragma force_active on

extern "C" void* fn_114_7D48(void* object, s16 size) {
    if (object != 0 && size > 0) {
        ::operator delete(object);
    }
    return object;
}
