#pragma force_active on
extern char lbl_27_data_20950[];

struct fn_27_C74BC_Obj {
    void *vtbl;
    void *unk4;
    int unk8;
    int unkC;
};

extern "C" {
void fn_27_C74BC(fn_27_C74BC_Obj *self, int a, int b) {
    self->unk4 = 0;
    self->vtbl = lbl_27_data_20950;
    self->unk8 = a;
    self->unkC = b;
    if (a == 0) {
        self->unkC = 0;
    }
}
}
