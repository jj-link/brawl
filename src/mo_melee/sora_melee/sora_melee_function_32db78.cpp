#pragma force_active on
extern "C" {
void fn_27_1E847C(void* self, int arg, void* data);
void __dl__FPv(void* p);
}

extern char lbl_27_data_88700[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_32DB78(void* self, int flag) {
    if (self) {
        char* base = lbl_27_data_88700;
        ((void**)self)[2] = base;
        ((void**)self)[0] = base + 8;
        fn_27_1E847C(self, 0x66, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
