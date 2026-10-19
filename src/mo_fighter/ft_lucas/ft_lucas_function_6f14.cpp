#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A3B48(void* ptr, short count);
void operator delete(void* object);

extern "C" void* fn_114_6F14(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A3B48(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
