#include <types.h>
#pragma force_active on

extern "C" void operator delete(void* p);

extern "C" void* fn_114_1A104(void* object, s16 size) {
    if (object != 0 && size > 0) {
        operator delete(object);
    }
    return object;
}
