#pragma force_active on
extern "C" void fn_27_3335CC(void*, int);
extern "C" void fn_27_333D6C(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3334B0(void* self, int flag) {
    if (self) {
        if ((char*)self + 0x4) {
            fn_27_3335CC((char*)self + 0x9C9C, -1);
            if ((char*)self + 0x8) {
                fn_27_3335CC((char*)self + 0x7D50, -1);
                if ((char*)self + 0xC) {
                    fn_27_3335CC((char*)self + 0x5E04, -1);
                    if ((char*)self + 0x10) {
                        fn_27_3335CC((char*)self + 0x3EB8, -1);
                        fn_27_333D6C((char*)self + 0x14, -1);
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
