#pragma force_active on

struct Fn2CUnk {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkC;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1C;
};

extern "C" void fn_802F5D5C(Fn2CUnk* self, unsigned int value) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0x80000000;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0x80000000;
    self->unkC = value;
    self->unk1C = 0;
}
