#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1FE4(void* object, s16 deleting);
extern "C" void* fn_111_4878(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_4800(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<u8*>(object) + 0x244, -1);
        if (object != 0) {
            fn_111_4878(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
