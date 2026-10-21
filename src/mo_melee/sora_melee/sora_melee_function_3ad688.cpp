#pragma force_active on
extern "C" void fn_27_3AD97C(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3AD688(char* self, int del) {
    if (self != 0) {
        if (self + 0x8 != 0 && self + 0x8 != 0 && self + 0xC != 0) {
            if (self + 0x4484 != 0) {
                fn_27_3AD97C((void*)(self + 0x4488), -1);
            }
            if (self + 0x10 != 0) {
                if (self + 0x2250 != 0) {
                    fn_27_3AD97C((void*)(self + 0x2254), -1);
                }
                if (self + 0x14 != 0 && self + 0x1C != 0) {
                    fn_27_3AD97C((void*)(self + 0x20), -1);
                }
            }
        }
        if (del > 0) {
            __dl__FPv((void*)self);
        }
    }
    return self;
}
