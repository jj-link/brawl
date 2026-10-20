#pragma force_active on
extern "C" {
extern char lbl_27_data_92F50[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int id, void* arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_372430(char* p, int del) {
    if (p) {
        char* d = lbl_27_data_92F50;
        *(char**)(p + 0) = d + 8;
        *(char**)(p + 8) = d;
        fn_27_1E847C(p, 0x4a, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
