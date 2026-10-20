#pragma force_active on
extern char lbl_27_data_33B48[];

struct fn_27_Obj {
    void* unk0;
    void* unk4;
    unsigned int unk8;
};

extern "C" void fn_27_1A6AE0(fn_27_Obj* self) {
    unsigned int flag = self->unk8;
    char* base = lbl_27_data_33B48;
    self->unk0 = base;
    self->unk4 = base + 0x48;
    self->unk8 = flag & 1;
}
