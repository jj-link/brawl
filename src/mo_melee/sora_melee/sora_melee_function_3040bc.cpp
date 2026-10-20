#pragma force_active on
extern "C" {
extern char lbl_27_data_82048[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int a, void* b);

struct Obj {
    void* vt0;
    int pad4;
    void* vt1;
};

Obj* fn_27_3040BC(Obj* p, int del) {
    if (p) {
        p->vt1 = lbl_27_data_82048;
        p->vt0 = lbl_27_data_82048 + 8;
        fn_27_1E847C(p, 0x62, lbl_27_bss_54EC);
        if (del > 0) {
            delete p;
        }
    }
    return p;
}
}
