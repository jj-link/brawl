#pragma force_active on
extern "C" {
extern char lbl_27_data_87D40[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int id, char* p);
void __dl__FPv(void*);
}

extern "C" void* fn_27_328CF8(void* self, int del) {
    if (self) {
        char* vt = lbl_27_data_87D40;
        ((void**)self)[2] = vt;
        ((void**)self)[0] = vt + 8;
        fn_27_1E847C(self, 0x95, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
