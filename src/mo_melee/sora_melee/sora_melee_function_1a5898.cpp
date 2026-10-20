#pragma force_active on
extern "C" {
extern char lbl_27_data_34AC8[0x90];
}

struct fn_27_S {
    void *vt;
    char *p4;
    unsigned int v8;
};

extern "C" void fn_27_1A5898(fn_27_S *s) {
    unsigned int t = s->v8;
    char *base = lbl_27_data_34AC8;
    s->vt = base;
    s->p4 = base + 0x48;
    s->v8 = t & 0xFFFF;
}
