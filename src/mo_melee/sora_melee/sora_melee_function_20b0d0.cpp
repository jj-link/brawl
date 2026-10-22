#pragma force_active on
#include <types.h>

extern "C" void fn_27_207DC0(void* a, int b, int c, void* d, int e);
extern "C" void fn_27_20B19C(void* a, int b, float c, float d);

struct TargetData {
    unsigned char unk0;
    char pad1[0x4F];
    int unk50;
    char pad54[8];
    float unk5C;
    float unk60;
    float unk64;
    char pad68[0xC];
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    char pad88[0x18];
    float unkA0;
    char padA4[0x10];
    int unkB4;
};

struct SourceData {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    int unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
};

extern "C" void fn_27_20B0D0(TargetData* self, SourceData* src, unsigned char* arg2) {
    fn_27_207DC0(self, -1, -1, 0, 0);
    self->unk0 = *arg2;
    self->unk50 = 0x80000004;
    if (!((u16)src->unk6 & 2)) {
        self->unk50 |= 1;
    }
    self->unkB4 = src->unk8;
    self->unk74 = src->unkC;
    self->unk78 = src->unk10;
    self->unk7C = src->unk14;
    self->unk5C = self->unk74;
    self->unk60 = self->unk78;
    self->unk64 = self->unk7C;
    self->unk80 = src->unk18;
    self->unk84 = src->unk1C;
    self->unkA0 = src->unk20;
    fn_27_20B19C(self, 0, self->unk78, self->unk74);
}
