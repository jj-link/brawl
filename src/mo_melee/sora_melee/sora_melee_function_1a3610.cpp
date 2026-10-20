#pragma force_active on
extern "C" {
extern char lbl_27_data_3B4B8[];

struct Fn1A3610Obj {
    void *m0;
    void *m4;
    unsigned int m8;
};

void fn_27_1A3610(Fn1A3610Obj *self) {
    unsigned int flag = self->m8;
    char *base = lbl_27_data_3B4B8;
    self->m0 = base;
    self->m4 = base + 0x48;
    self->m8 = flag & 1;
}
}
