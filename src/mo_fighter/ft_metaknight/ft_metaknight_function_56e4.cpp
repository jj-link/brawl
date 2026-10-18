#include <types.h>
#pragma force_active on

extern "C" void fn_111_3DF4(void* object, s16 deleting);

extern "C" void* fn_111_56E4(void* object, s16 deleting) {
    if (object) {
        if (object) {
            fn_111_3DF4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
