#include <types.h>
#pragma force_active on

extern "C" void* fn_111_20E8(void* object, s16 deleting);
extern "C" void* fn_111_2184(void* object, s16 deleting);
extern "C" void* fn_111_21C4(void* object, s16 deleting);
extern "C" void* fn_27_C7770(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_F8D0(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_20E8(static_cast<u8*>(object) + 0xDC, -1);
        fn_111_2184(static_cast<u8*>(object) + 0xC0, -1);
        fn_111_21C4(static_cast<u8*>(object) + 0x14, -1);

        if (object != 0) {
            fn_27_C7770(object, -1);
        }

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
