#include <types.h>
#pragma force_active on

extern "C" void fn_111_194C(void*, s16);
extern "C" void fn_111_1D2C(void*, s16);
extern "C" void fn_111_1DC8(void*, s16);
extern "C" void fn_111_1F00(void*, s16);
extern "C" void* fn_27_125E20(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_18AC(void* self, s16 p2) {
    if (self != NULL) {
        fn_111_194C((u8*)self + 0xA554, -1);
        fn_111_1D2C((u8*)self + 0xA09C, -1);
        fn_111_1DC8((u8*)self + 0xA060, -1);
        fn_111_1F00((u8*)self + 0x194, -1);
        fn_27_125E20(self, 0);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
