#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A18A0(void*, short);
extern "C" void* fn_111_4698(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_4620(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<u8*>(object) + 0x354, -1);
        if (object != 0) {
            fn_111_4698(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
