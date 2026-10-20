#pragma force_active on
extern char lbl_27_data_33E30[0x90];

struct fn_27_Obj {
    void *m0;
    void *m4;
    unsigned int m8;
};

extern "C" {
void fn_27_1A67D4(fn_27_Obj *p) {
    unsigned int v = p->m8;
    char *base = lbl_27_data_33E30;
    p->m0 = base;
    p->m4 = base + 0x48;
    p->m8 = v & 1;
}
}
