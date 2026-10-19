#include <types.h>
#pragma force_active on

extern "C" void* fn_111_228C(void* object, s16 deleting);
extern "C" void* fn_111_20E8(void* object, s16 deleting);
extern "C" void __dl__FPv(void* block);

extern "C" void* fn_111_2220(void* object, s16 deleting) {
    if (object != 0) {
        s16 flag = -1;
        fn_111_228C(static_cast<u8*>(object) + 0x50, flag);
        fn_111_20E8(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
