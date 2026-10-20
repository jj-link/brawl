#pragma force_active on
struct Obj {
    void *vt;
    char *p;
    unsigned int flags;
};

extern "C" char lbl_27_data_33860[0x90];

extern "C" void fn_27_1A6DEC(Obj *o) {
    unsigned int f = o->flags;
    o->vt = lbl_27_data_33860;
    o->p = lbl_27_data_33860 + 0x48;
    o->flags = f & 1;
}
