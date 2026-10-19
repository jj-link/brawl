#include <types.h>
#pragma force_active on

extern "C" void* fn_111_1E48(void* object, s16 deleting);
extern "C" void fn_111_1EA4(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_3D2C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_1E48(static_cast<u8*>(object) + 0x14, 0);
        fn_111_1EA4(static_cast<u8*>(object) + 0x8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
