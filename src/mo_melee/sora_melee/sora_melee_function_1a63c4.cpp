#pragma force_active on
struct Obj {
    void *m0;
    void *m4;
    unsigned int m8;
};

extern "C" {
extern char lbl_27_data_34210[];
}

extern "C" void fn_27_1A63C4(Obj *p) {
    unsigned int flag = p->m8;
    char *base = lbl_27_data_34210;
    p->m0 = base;
    p->m4 = base + 0x48;
    p->m8 = flag & 1;
}
