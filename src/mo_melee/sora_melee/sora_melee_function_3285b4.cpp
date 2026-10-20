#pragma force_active on
struct Obj {
    void* vt0;
    unsigned int pad4;
    void* vt8;
};

extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void __dl__FPv(void*);
extern char lbl_27_data_87860[];
extern char lbl_27_bss_54EC[];

extern "C" {
Obj* fn_27_3285B4(Obj* p, int del) {
    if (p) {
        p->vt8 = lbl_27_data_87860;
        p->vt0 = lbl_27_data_87860 + 8;
        fn_27_1E847C(p, 10, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
