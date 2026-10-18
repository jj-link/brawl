#include <types.h>
#pragma force_active on

extern "C" void fn_111_3B68(void* object, s16 flag);
extern "C" void fn_111_3BEC(void* object, s16 flag);
extern "C" void fn_111_FF6C(void* object, s16 flag);
extern "C" void fn_111_FFC8(void* object, s16 flag);
extern "C" void fn_111_100FC(void* object, s16 flag);
extern "C" void fn_27_C74E8(void* object, s16 flag);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_FED0(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3B68(static_cast<u8*>(object) + 0x110, -1);
        fn_111_3BEC(static_cast<u8*>(object) + 0xFC, -1);
        fn_111_FF6C(static_cast<u8*>(object) + 0xEC, -1);
        fn_111_FFC8(static_cast<u8*>(object) + 0x48, -1);
        fn_111_100FC(static_cast<u8*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
