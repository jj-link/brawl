#pragma force_active on
extern char lbl_27_data_20950[];

struct fn_27_C749C_Obj {
    void* vtbl;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};

extern "C" void fn_27_C749C(fn_27_C749C_Obj* self) {
    self->f4 = 0;
    self->vtbl = lbl_27_data_20950;
    self->f8 = 0;
    self->fC = 0;
}
