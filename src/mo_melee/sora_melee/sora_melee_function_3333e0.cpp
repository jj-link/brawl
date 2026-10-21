#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_3335CC(void*, s32);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3333E0(u8* self, s32 flag) {
    if (self) {
        if (self && (self + 0x4)) {
            fn_27_3335CC(self + 0x9C9C, -1);
            if (self + 0x8) {
                fn_27_3335CC(self + 0x7D50, -1);
                if (self + 0xC) {
                    fn_27_3335CC(self + 0x5E04, -1);
                    if (self + 0x10) {
                        fn_27_3335CC(self + 0x3EB8, -1);
                        if (self + 0x14) {
                            fn_27_3335CC(self + 0x1F6C, -1);
                            if (self + 0x18) {
                                fn_27_3335CC(self + 0x20, -1);
                            }
                        }
                    }
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
