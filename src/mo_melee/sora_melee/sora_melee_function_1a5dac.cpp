#pragma force_active on
struct Obj {
    void *vt;
    char *ptr4;
    unsigned int flags;
};

extern "C" {
extern char lbl_27_data_3B3C0[];

void fn_27_1A5DAC(Obj *p) {
    unsigned int f = p->flags;
    char *base = lbl_27_data_3B3C0;
    char *p4 = base + 0x48;
    p->vt = base;
    p->ptr4 = p4;
    p->flags = f & 1;
}
}
