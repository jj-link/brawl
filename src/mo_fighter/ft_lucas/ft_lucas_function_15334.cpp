#include <types.h>
#pragma force_active on

extern "C" void* fn_114_152F4(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_15334(void* object, short deleting) {
    if (object != 0) {
        fn_114_152F4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
