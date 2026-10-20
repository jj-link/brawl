#pragma force_active on
extern "C" {
void fn_27_1E847C(void*, int, void*);
extern char lbl_27_data_9DA28[];
extern char lbl_27_bss_54EC[];
void __dl__FPv(void*);
}

extern "C" void* fn_27_3A7F2C(void* self, int flag) {
    if (self) {
        ((void**)self)[0] = lbl_27_data_9DA28 + 8;
        ((void**)self)[2] = lbl_27_data_9DA28;
        fn_27_1E847C(self, 0x8b, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
