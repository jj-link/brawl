#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1C558(void* object, s16 flags) {
    if (object != nullptr && flags > 0) {
        ::operator delete(object);
    }
    return object;
}
