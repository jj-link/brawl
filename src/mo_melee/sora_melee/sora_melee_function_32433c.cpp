#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern char lbl_27_data_86930[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int flag, void* bss);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_32433C(void* p, int doDelete) {
    if (p != 0) {
        u32* obj = (u32*)p;
        obj[2] = (u32)lbl_27_data_86930;
        obj[0] = (u32)lbl_27_data_86930 + 8;
        fn_27_1E847C(p, 0x1f, lbl_27_bss_54EC);
        if (doDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
