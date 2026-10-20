#pragma force_active on
extern "C" {
extern char lbl_27_data_8D6B8[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int id, void* p);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_34CD68(void* p, int flag) {
    if (p) {
        ((void**)p)[0] = lbl_27_data_8D6B8 + 8;
        ((void**)p)[2] = lbl_27_data_8D6B8;
        fn_27_1E847C(p, 0x6d, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
