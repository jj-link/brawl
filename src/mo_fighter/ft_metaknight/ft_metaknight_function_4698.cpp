#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2904(void* member, s16 deleteFlag);
extern "C" void fn_111_4710(void* object, s16 flag);

#pragma dont_inline on
extern "C" void* fn_111_4698(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<u8*>(object) + 0x318, -1);
        if (object != 0) {
            fn_111_4710(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
