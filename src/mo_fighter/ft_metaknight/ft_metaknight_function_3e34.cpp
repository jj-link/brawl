#include <types.h>
#pragma force_active on

extern "C" void* fn_27_3544C(void* object, s16 deleting);

extern "C" void* fn_111_3E34(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_3544C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
