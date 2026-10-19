#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1E70(void* object, s16 value);
extern "C" void* fn_111_4D20(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_4CB0(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<u8*>(object) + 0x1C, -1);
        fn_111_4D20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
