#include <types.h>
#pragma force_active on

extern "C" void* fn_111_3C4C(void* object, s16 deleting);
extern "C" void* fn_111_5AB8(void* object, s16 deleting);
extern "C" void* fn_27_CD934(void* object, s16 deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_111_5A40(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_3C4C((u8*)object + 0xAC, -1);
        fn_111_5AB8((u8*)object + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
