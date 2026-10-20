#pragma force_active on
extern "C" {
extern char lbl_27_data_35158[0x90];

struct FnObj {
    char* unk0;
    char* unk4;
    unsigned int unk8;
};

void fn_27_1A4F74(FnObj* self) {
    char* base = lbl_27_data_35158;
    char* next = base + 0x48;
    self->unk0 = base;
    self->unk4 = next;
    self->unk8 &= 0xFFFF;
}
}
