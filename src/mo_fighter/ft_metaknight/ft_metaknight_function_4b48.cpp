#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, s16 deleteFlag);
extern "C" void* fn_111_4BC0(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_4B48(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<u8*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_111_4BC0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
