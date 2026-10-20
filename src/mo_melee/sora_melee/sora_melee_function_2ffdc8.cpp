#pragma force_active on
extern "C" void fn_27_1E847C(void* self, int flag, void* data);
extern "C" void __dl__FPv(void* p);

extern char lbl_27_data_81608[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_2FFDC8(void* self, int del) {
    if (self) {
        *(char**)((char*)self + 0x0) = lbl_27_data_81608 + 8;
        *(char**)((char*)self + 0x8) = lbl_27_data_81608;
        fn_27_1E847C(self, 0x53, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
