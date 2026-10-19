#include <types.h>
#pragma force_active on

extern "C" void fn_27_1362C(void*, short);

extern "C" void* fn_111_1EA4(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1362C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
