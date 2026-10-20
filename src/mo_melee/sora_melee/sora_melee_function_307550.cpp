#pragma force_active on
extern char lbl_27_data_826B0[];
extern char lbl_27_bss_54EC[];
extern "C" {
void fn_27_1E847C(void* self, int flags, char* p);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_307550(void* self, int flags) {
    if (self != 0) {
        ((void**)self)[2] = lbl_27_data_826B0;
        ((void**)self)[0] = lbl_27_data_826B0 + 8;
        fn_27_1E847C(self, 0x40, lbl_27_bss_54EC);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
