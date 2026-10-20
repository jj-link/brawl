#pragma force_active on
extern "C" void fn_27_1E847C(void* self, int flag, void* vt);
extern "C" void __dl__FPv(void* p);
extern char lbl_27_data_926F8[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_36DAC0(void* self, int flag) {
    if (self) {
        ((void**)self)[0] = lbl_27_data_926F8 + 0x8;
        ((void**)self)[2] = lbl_27_data_926F8;
        fn_27_1E847C(self, 0xd, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
