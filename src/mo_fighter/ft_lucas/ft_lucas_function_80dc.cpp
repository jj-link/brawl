#include <types.h>
#pragma force_active on

extern "C" void fn_27_48BE8(void*, short);
extern "C" void fn_27_47CCC(void*, short);
extern "C" void fn_27_19958C(void*, short);
extern "C" void fn_27_19FCBC(void*, short);
extern "C" void fn_27_19DCC0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_80DC(u8* self, short deleteFlag) {
    if (self != 0) {
        short destroy = -1;
        fn_27_48BE8(self + 0x904, destroy);
        fn_27_47CCC(self + 0x8F4, destroy);
        fn_27_19958C(self + 0x780, destroy);
        fn_27_19FCBC(self + 0x54C, destroy);
        fn_27_19DCC0(self, destroy);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
