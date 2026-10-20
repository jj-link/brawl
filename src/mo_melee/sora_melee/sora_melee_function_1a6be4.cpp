#pragma force_active on
struct Obj {
    void *p0;
    void *p4;
    unsigned int f8;
};

extern "C" extern char lbl_27_data_33A50[];

extern "C" void fn_27_1A6BE4(Obj *o) {
    unsigned int v = o->f8;
    char *b = lbl_27_data_33A50;
    char *c = b + 0x48;
    o->p0 = b;
    o->p4 = c;
    o->f8 = v & 1;
}
