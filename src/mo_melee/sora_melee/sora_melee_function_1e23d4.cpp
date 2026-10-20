#pragma force_active on
extern "C" void fn_27_1E847C(void* self, int arg, char* p);
extern "C" void __dl__FPv(void*);
extern char lbl_27_data_466C8[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_1E23D4(void* p, int flag) {
    if (p) {
        char* vt = lbl_27_data_466C8;
        *(char**)((char*)p + 8) = vt;
        *(char**)p = vt + 8;
        fn_27_1E847C(p, 0x85, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
