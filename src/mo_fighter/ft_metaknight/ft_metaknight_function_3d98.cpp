#include <types.h>
#pragma force_active on

extern "C" void* fn_27_A1E80(void* object, short);

extern "C" void* fn_111_3D98(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_A1E80(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
