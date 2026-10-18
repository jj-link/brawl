#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_114_1FCC(void* object, s16 flags) {
    if (object != 0 && flags > 0) {
        operator delete(object);
    }
    return object;
}
