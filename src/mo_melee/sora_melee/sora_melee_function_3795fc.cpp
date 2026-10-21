#pragma force_active on

extern "C" void fn_27_3797E8(void*, int);
extern "C" void fn_27_37A2D0(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3795FC(char* self, int del) {
    if (self != 0) {
        if (self != 0) {
            if ((self + 0x2080) != 0 && (self + 0x2088) != 0) {
                fn_27_3797E8(self + 0x208c, -1);
            }

            if (self != 0) {
                if (self != 0) {
                    if ((self + 0x4) != 0 && (self + 0xc) != 0) {
                        fn_27_37A2D0(self + 0x10, -1);
                    }
                }
            }
        }

        if (del > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
