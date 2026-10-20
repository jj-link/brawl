#include <types.h>
#pragma force_active on

extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_102_1183C(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_117B4(void* self, s32 arg) {
    if (self != 0) {
        s32 val = -1;
        fn_27_93100((char*)self + 0x10000 - 0x4240, (short)val);
        fn_102_1183C((char*)self + 0x7c, (short)val);
        fn_27_19F4C4((char*)self + 0x20, (short)val);
        fn_27_1A55B0(self, (short)val);
        if ((s16)arg > 0) __dl__FPv(self);
    }
    return self;
}
