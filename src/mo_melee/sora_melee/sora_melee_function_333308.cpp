#pragma force_active on
extern "C" void fn_27_3335CC(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_333308(char* self, int del) {
    if (self != 0) {
        if (self + 0x8 != 0 && self + 0x8 != 0 && self + 0xC != 0) {
            fn_27_3335CC((void*)(self + 0x9CA4), -1);
            if (self + 0x10 != 0) {
                fn_27_3335CC((void*)(self + 0x7D58), -1);
                if (self + 0x14 != 0) {
                    fn_27_3335CC((void*)(self + 0x5E0C), -1);
                    if (self + 0x18 != 0) {
                        fn_27_3335CC((void*)(self + 0x3EC0), -1);
                        if (self + 0x1C != 0) {
                            fn_27_3335CC((void*)(self + 0x1F74), -1);
                            if (self + 0x20 != 0) {
                                fn_27_3335CC((void*)(self + 0x28), -1);
                            }
                        }
                    }
                }
            }
        }
        if (del > 0) {
            __dl__FPv((void*)self);
        }
    }
    return self;
}
