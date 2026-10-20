#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1CFC(void* member, s16 deleteFlag);
extern "C" void* fn_111_44B8(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_4440(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<u8*>(object) + 0x524, -1);
        if (object != 0) {
            fn_111_44B8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
