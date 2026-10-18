#include <types.h>
#pragma force_active on

extern "C" void* fn_111_4440(void* object, s16 deleting);

extern "C" void* fn_111_43E0(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_111_4440(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
