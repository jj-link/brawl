#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void* fn_111_205C(void*, s16);
void* fn_111_2220(void*, s16);
void* fn_111_22E8(void*, s16);
void* fn_111_2374(void*, s16);
void* fn_111_2400(void*, s16);
void* fn_111_248C(void*, s16);
void* fn_111_2518(void*, s16);
void* fn_111_25A4(void*, s16);
void* fn_111_2630(void*, s16);
void* fn_111_26BC(void*, s16);
void* fn_111_2748(void*, s16);
}

extern "C" void* fn_111_1F84(void* object, s16 deleting) {
    if (object != 0) {
        u8* base = static_cast<u8*>(object);
        s16 destroy = -1;
        fn_111_205C(base + 0x14c8, destroy);
        fn_111_2220(base + 0x13a4, destroy);
        fn_111_22E8(base + 0x1278, destroy);
        fn_111_2374(base + 0x114c, destroy);
        fn_111_2400(base + 0x1020, destroy);
        fn_111_248C(base + 0xef4, destroy);
        fn_111_2518(base + 0xdc8, destroy);
        fn_111_25A4(base + 0xc9c, destroy);
        fn_111_2630(base + 0xb70, destroy);
        fn_111_26BC(base + 0xa44, destroy);
        fn_111_2748(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
