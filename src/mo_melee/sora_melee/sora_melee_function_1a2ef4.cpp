#pragma force_active on
struct Obj {
    void *p0;
    char *p4;
    unsigned int p8;
};

extern char lbl_27_data_36C68[];

extern "C" void fn_27_1A2EF4(Obj *self) {
    unsigned int v = self->p8;
    char *base = lbl_27_data_36C68;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = v & 0x1FFF;
}
