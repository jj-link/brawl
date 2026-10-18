#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6880C(void*, s16);

extern "C" void* fn_111_1039C(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
