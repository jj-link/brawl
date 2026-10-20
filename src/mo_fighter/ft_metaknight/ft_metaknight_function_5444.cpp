#include <types.h>
#pragma force_active on

extern "C" void fn_27_48BE8(void*, s16);
extern "C" void fn_27_47CCC(void*, s16);
extern "C" void fn_27_CB800(void*, s16);
extern "C" void fn_27_19FB24(void*, s16);
extern "C" void fn_27_19E5E0(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_5444(void* object, s16 destroy) {
    if (object != 0) {
        fn_27_48BE8(static_cast<u8*>(object) + 0xA14, -1);
        fn_27_47CCC(static_cast<u8*>(object) + 0xA04, -1);
        fn_27_CB800(static_cast<u8*>(object) + 0x908, -1);
        fn_27_19FB24(static_cast<u8*>(object) + 0x78C, -1);
        fn_27_19E5E0(object, -1);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
