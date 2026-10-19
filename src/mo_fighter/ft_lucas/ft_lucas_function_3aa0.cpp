#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_3AA0(void* object, short deleting) {
    if (object != 0) {
        fn_114_3A20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
