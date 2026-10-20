#pragma force_active on
extern "C" {
extern char lbl_27_data_349D0[];
}

struct fn_27_Obj {
    void *p0;
    char *p4;
    unsigned int p8;
};

extern "C" void fn_27_1A599C(fn_27_Obj *self) {
    unsigned int v = self->p8;
    char *base = lbl_27_data_349D0;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = v & 1;
}
