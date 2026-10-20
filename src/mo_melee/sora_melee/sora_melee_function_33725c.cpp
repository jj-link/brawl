#pragma force_active on
extern "C" {
extern char lbl_27_data_8A1E0[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void*, int, char*);
void __dl__FPv(void*);
}

extern "C" void* fn_27_33725C(void* p, int del) {
    if (p) {
        char* d = lbl_27_data_8A1E0;
        ((char**)p)[2] = d;
        ((char**)p)[0] = d + 8;
        fn_27_1E847C(p, 0x5d, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
