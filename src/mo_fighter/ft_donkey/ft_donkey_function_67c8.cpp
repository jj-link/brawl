#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_22A38(void*, s16);
void fn_27_1A2910(void*, s16);
void __dl__FPv(void*);
}

extern "C" void* fn_92_67C8(void* object, s16 deleting) {
    if (object) {
        u8* storage = (u8*)object;
        fn_27_22A38(storage + 0x34, (s16)-1);
        fn_27_1A2910(object, (s16)-1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
