#pragma force_active on
extern "C" {
extern char lbl_27_data_862F0[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int a, void* b);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_322218(void* self, int flag) {
    if (self) {
        ((void**)self)[0] = lbl_27_data_862F0 + 8;
        ((void**)self)[2] = lbl_27_data_862F0;
        fn_27_1E847C(self, 0x1e, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
