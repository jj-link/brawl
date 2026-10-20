#pragma force_active on
struct fn27Obj {
    void *vtbl;
    char *ptr4;
    unsigned int flag;
};

extern "C" {
extern char lbl_27_data_35CE8[];

void fn_27_1A4344(fn27Obj *o) {
    unsigned int flag = o->flag;
    char *base = lbl_27_data_35CE8;
    flag &= 1;
    o->vtbl = base;
    o->ptr4 = base + 0x48;
    o->flag = flag;
}
}
