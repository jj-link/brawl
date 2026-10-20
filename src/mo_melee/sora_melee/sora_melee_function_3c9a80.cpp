#pragma force_active on
extern "C" {
void fn_27_1E847C(void*, int, void*);
void __dl__FPv(void*);
}
extern char lbl_27_data_A36B8[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_3C9A80(void* self, int flags) {
    if (self != 0) {
        void** p = (void**)self;
        p[2] = lbl_27_data_A36B8;
        p[0] = lbl_27_data_A36B8 + 8;
        fn_27_1E847C(self, 0x26, lbl_27_bss_54EC);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
