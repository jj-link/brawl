#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7928(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A15B8(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
