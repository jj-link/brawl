#pragma force_active on
struct Obj {
    void *m0;
    void *m4;
    unsigned int m8;
};

extern "C" char lbl_27_data_34308[];

extern "C" void fn_27_1A62C0(Obj *self) {
    unsigned int flag = self->m8;
    char *base = lbl_27_data_34308;
    char *alt = base + 0x48;
    self->m0 = base;
    self->m4 = alt;
    self->m8 = flag & 1;
}
