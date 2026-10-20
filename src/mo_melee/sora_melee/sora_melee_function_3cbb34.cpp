#pragma force_active on
extern "C" {
extern char lbl_27_data_A3CB0[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* p, int size, char* bss);
}

extern "C" void* fn_27_3CBB34(void* p, int del) {
    if (p != 0) {
        ((void**)p)[0] = lbl_27_data_A3CB0 + 8;
        ((void**)p)[2] = lbl_27_data_A3CB0;
        fn_27_1E847C(p, 0x27, lbl_27_bss_54EC);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
