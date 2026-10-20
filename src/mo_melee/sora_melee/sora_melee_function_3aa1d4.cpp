#pragma force_active on
extern char lbl_27_data_9DFD0[];
extern char lbl_27_bss_54EC[];
extern "C" void fn_27_1E847C(void* self, int size, char* bss);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_3AA1D4(void* self, int deleteFlag) {
    if (self != 0) {
        *(char**)((char*)self + 0x8) = lbl_27_data_9DFD0;
        *(char**)self = lbl_27_data_9DFD0 + 0x8;
        fn_27_1E847C(self, 0x8c, lbl_27_bss_54EC);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
