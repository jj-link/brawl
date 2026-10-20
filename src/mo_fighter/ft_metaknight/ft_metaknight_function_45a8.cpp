#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void* object, s16 deleting);
extern "C" void* fn_111_4620(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_45A8(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<u8*>(object) + 0x470, -1);
        if (object != 0) {
            fn_111_4620(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
