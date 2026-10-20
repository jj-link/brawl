#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_35430[];

struct fn_27_Obj {
    void *base;
    void *cur;
    unsigned int n;
};

void fn_27_1A4C68(fn_27_Obj *o) {
    unsigned int n = o->n;
    unsigned char *b = lbl_27_data_35430;
    unsigned char *c = b + 0x48;
    n &= 0xFFFF;
    o->base = b;
    o->cur = c;
    o->n = n;
}
}
