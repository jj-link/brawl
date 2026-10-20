#pragma force_active on
struct Fn27Obj {
    char* unk0;
    char* unk4;
    unsigned int unk8;
};

extern char lbl_27_data_35AF8[0x90];

extern "C" void fn_27_1A454C(Fn27Obj* self) {
    unsigned int flag = self->unk8;
    char* base = lbl_27_data_35AF8;
    char* next = base + 0x48;
    self->unk0 = base;
    self->unk4 = next;
    self->unk8 = flag & 1;
}
