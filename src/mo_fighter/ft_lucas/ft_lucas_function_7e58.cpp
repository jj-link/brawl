#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1540CC(void* object, short param);
void operator delete(void* object);

extern "C" void* fn_114_7E58(void* object, short deleting) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
