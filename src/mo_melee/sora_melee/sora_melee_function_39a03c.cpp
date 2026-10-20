#pragma force_active on
extern "C" void fn_27_1E847C(void* self, int kind, void* data);
extern "C" void __dl__FPv(void* p);
extern char lbl_27_data_9B4F8[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_39A03C(void* self, int del) {
    if (self) {
        ((void**)self)[2] = lbl_27_data_9B4F8;
        ((void**)self)[0] = lbl_27_data_9B4F8 + 8;
        fn_27_1E847C(self, 0x35, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
