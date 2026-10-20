#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_3AD97C(void*, s32);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3ADCB0(u8* self, s32 flag) {
    if (self) {
        if (self + 0x2240) {
            fn_27_3AD97C(self + 0x2244, -1);
        }
        if (self + 0x4) {
            if (self + 0xC) {
                fn_27_3AD97C(self + 0x10, -1);
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
