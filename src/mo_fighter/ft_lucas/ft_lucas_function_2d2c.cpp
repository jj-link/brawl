#include <types.h>
#pragma force_active on

extern "C" void* fn_27_14CD30(void*, short);
void operator delete(void*);

extern "C" void* fn_114_2D2C(void* object, short deleting) {
    if (object != 0) {
        fn_27_14CD30(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
