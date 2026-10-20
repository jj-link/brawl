#pragma force_active on
extern char lbl_27_data_8F0C0[];
extern char lbl_27_bss_54EC[];
extern "C" void fn_27_1E847C(void* self, int size, void* data);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_355F78(void* self, int del) {
    if (self) {
        ((void**)self)[0] = lbl_27_data_8F0C0 + 8;
        ((void**)self)[2] = lbl_27_data_8F0C0;
        fn_27_1E847C(self, 0x24, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
