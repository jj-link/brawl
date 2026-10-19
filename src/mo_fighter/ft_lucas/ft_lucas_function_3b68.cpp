#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C31CC(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_3B68(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
