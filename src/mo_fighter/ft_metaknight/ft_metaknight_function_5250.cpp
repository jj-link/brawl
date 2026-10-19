#include <types.h>
#pragma force_active on

extern "C" void fn_27_1540CC(void*, short);

extern "C" void* fn_111_5250(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
