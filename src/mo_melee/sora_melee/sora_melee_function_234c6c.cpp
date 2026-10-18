#pragma force_active on
extern "C" unsigned char lbl_27_data_4C3EC[0x24];

struct Object {
    unsigned int unk0;
    void* unk4;
    unsigned int unk8;
    unsigned char unkC;
};

extern "C" Object* fn_27_234C6C(Object* self, unsigned int value, unsigned char flag) {
    self->unk0 = 0;
    self->unk8 = value;
    self->unkC = flag;
    self->unk4 = lbl_27_data_4C3EC;
    return self;
}
