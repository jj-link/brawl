#include <types.h>
#pragma force_active on

extern "C" void* fn_111_F6C0(void* object, s16 deleting);
extern "C" void* fn_111_F72C(void* object, s16 deleting);
extern "C" void* fn_111_F7B8(void* object, s16 flag);
extern "C" void* fn_111_F844(void* object, s16 deleting);
extern "C" void* fn_111_F8D0(void* object, s16 deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_111_F630(void* object, s16 deleting) {
    if (object != 0) {
        u8* base = static_cast<u8*>(object);
        fn_111_F6C0(base + 0x4B0, -1);
        fn_111_F72C(base + 0x384, -1);
        fn_111_F7B8(base + 0x258, -1);
        fn_111_F844(base + 0x12C, -1);
        fn_111_F8D0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
