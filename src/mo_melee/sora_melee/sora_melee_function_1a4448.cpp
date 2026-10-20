#pragma force_active on
struct fn_27_1A4448_obj {
    char *m0;
    char *m4;
    unsigned int m8;
};

extern "C" {
extern char lbl_27_data_35BF0[];
}

extern "C" void fn_27_1A4448(fn_27_1A4448_obj *self) {
    unsigned int flag = self->m8;
    char *p = lbl_27_data_35BF0;
    char *q = p + 0x48;
    self->m0 = p;
    self->m4 = q;
    self->m8 = flag & 1;
}
