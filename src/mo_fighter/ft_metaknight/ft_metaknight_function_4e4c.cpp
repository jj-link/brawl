#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A2524(void* ptr, s16 arg);
extern "C" void* fn_111_3CEC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_4E4C(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<u8*>(object) + 0x10, -1);
        fn_111_3CEC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
