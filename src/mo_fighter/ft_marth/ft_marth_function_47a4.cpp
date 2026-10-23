#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_48BE8(void*, s16);
void* fn_27_47CCC(void*, s16);
void* fn_27_CB800(void*, s16);
void* fn_27_19FB24(void*, s16);
void* fn_27_19E5E0(void*, s16);
void __dl__FPv(void*);

void* fn_106_47A4(void* obj, s16 p1) {
    if (obj) {
        fn_27_48BE8(static_cast<u8*>(obj) + 0xa14, -1);
        fn_27_47CCC(static_cast<u8*>(obj) + 0xa04, -1);
        fn_27_CB800(static_cast<u8*>(obj) + 0x908, -1);
        fn_27_19FB24(static_cast<u8*>(obj) + 0x78c, -1);
        fn_27_19E5E0(obj, -1);
        if (p1 > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
