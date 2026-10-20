#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, s16);
extern "C" void* fn_111_4788(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_4710(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<u8*>(object) + 0x2FC, -1);
        if (object != 0) {
            fn_111_4788(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
