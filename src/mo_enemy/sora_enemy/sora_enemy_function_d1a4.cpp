#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_41_C8D0(void* p);

struct Unk {
    u8 unk0;
    u8 pad1[3];
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
};

extern "C" void fn_41_D1A4(Unk* self, u32 a, u32 b, u32 c, u32 d) {
    fn_41_C8D0(self);
    self->unk14 = a;
    self->unk0 = 1;
    self->unk4 = b;
    self->unk8 = 0x10000 - 1;
    self->unkC = c;
    self->unk10 = d;
}
