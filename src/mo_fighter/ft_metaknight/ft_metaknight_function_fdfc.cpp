#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A241C(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_FDFC(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A241C(static_cast<u8*>(object) + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
