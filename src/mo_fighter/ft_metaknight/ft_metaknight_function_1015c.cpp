#include <types.h>
#pragma force_active on

extern "C" void* fn_111_101C8(void* object, s16 deleting);
extern "C" void fn_111_3D2C(void* object, s16 param);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_111_1015C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_101C8(static_cast<u8*>(object) + 0x24, -1);
        fn_111_3D2C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
