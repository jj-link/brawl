#include <types.h>
#pragma force_active on

extern "C" void* fn_111_21C4(void* object, s16 deleting);
extern "C" void* fn_111_20E8(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_F6C0(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_21C4(static_cast<u8*>(object) + 0x50, -1);
        fn_111_20E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
