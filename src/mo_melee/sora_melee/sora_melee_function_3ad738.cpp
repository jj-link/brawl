#pragma force_active on
extern "C" void fn_27_3AD97C(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3AD738(char* self, int del) {
    if (self != 0) {
        if (self != 0 && self + 0x4 != 0) {
            if (self + 0x447C != 0) {
                fn_27_3AD97C((void*)(self + 0x4480), -1);
            }
            if (self + 0x8 != 0) {
                if (self + 0x2248 != 0) {
                    fn_27_3AD97C((void*)(self + 0x224C), -1);
                }
                if (self + 0xC != 0 && self + 0x14 != 0) {
                    fn_27_3AD97C((void*)(self + 0x18), -1);
                }
            }
        }
        if (del > 0) {
            __dl__FPv((void*)self);
        }
    }
    return self;
}