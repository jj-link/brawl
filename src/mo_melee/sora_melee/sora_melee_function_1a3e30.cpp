#pragma force_active on
struct fn27Obj {
    void *p0;
    void *p1;
    unsigned int flag;
};

extern char lbl_27_data_360C8[];

extern "C" void fn_27_1A3E30(fn27Obj *o) {
    unsigned int f = o->flag;
    char *base = lbl_27_data_360C8;
    o->p0 = base;
    o->p1 = base + 0x48;
    o->flag = f & 1;
}
