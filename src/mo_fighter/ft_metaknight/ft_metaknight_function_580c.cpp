#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void* fn_111_3F04(void*, s16);
void* fn_111_58C0(void*, s16);
void* fn_111_592C(void*, s16);
void* fn_111_5988(void*, s16);
void* fn_111_59E4(void*, s16);
void* fn_111_5A40(void*, s16);
void* fn_27_13C90(void*, s16);
void* fn_27_21038(void*, s16);
}

extern "C" void* fn_111_580C(void* object, s16 deleting) {
    if (object != 0) {
        s16 destroy = -1;
        fn_27_13C90(static_cast<u8*>(object) + 0x224, destroy);
        fn_111_58C0(static_cast<u8*>(object) + 0x1e8, destroy);
        fn_27_21038(static_cast<u8*>(object) + 0x1d8, destroy);
        fn_111_592C(static_cast<u8*>(object) + 0x1b8, destroy);
        fn_111_5988(static_cast<u8*>(object) + 0x198, destroy);
        fn_111_3F04(static_cast<u8*>(object) + 0x160, destroy);
        fn_111_59E4(static_cast<u8*>(object) + 0xc4, destroy);
        fn_111_5A40(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
