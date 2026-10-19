#include <types.h>
#pragma force_active on

extern "C" void* fn_114_34F4(void* object, s16 deleting);
void operator delete(void* object);

extern "C" void* fn_114_3498(void* object, short deleting) {
    if (object != 0) {
        fn_114_34F4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
