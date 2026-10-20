#pragma force_active on
extern "C" {
extern char lbl_27_data_88FE0[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int kind, void* p);
void __dl__FPv(void* p);

void* fn_27_330E1C(void* self, int flag) {
    if (self) {
        void** p = (void**)self;
        p[2] = lbl_27_data_88FE0;
        p[0] = lbl_27_data_88FE0 + 8;
        fn_27_1E847C(self, 0x73, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
