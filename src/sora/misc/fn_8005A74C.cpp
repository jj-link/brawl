#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8042E980[];
extern void* lbl_805A0110;
extern f32 lbl_805A18D0;
extern f32 lbl_805A18D4;
void fn_8005AD04();
void fn_8005BB58(void* self, void* node);
}

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    union {
        u32 w;
        u8 b[4];
        struct {
            u32 type : 8;
            u32 rest : 24;
        } f;
    } unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    char* unk48;
};

extern "C" void* fn_8005A74C(Obj* self, s32 arg1, s8 arg2) {
    f32 f0 = 1.0f;
    f32 f1 = 0.0f;
    s32 zero = 0;
    s32 one = 1;
    self->unk48 = lbl_8042E980;
    self->unk0 = zero;
    self->unk4 = zero;
    self->unkC.f.type = one;
    self->unk8 = arg1;
    self->unkC.b[2] = arg2;
    self->unkC.b[3] = one;
    self->unk10 = f1;
    self->unk14 = f1;
    self->unk18 = f0;
    self->unk1C = zero;
    self->unk22 = zero;
    self->unkC.b[1] = ((self->unkC.b[1] & ~0x80) | 0x40) & ~0x20;
    self->unk20 = zero;
    self->unk2C = f1;
    self->unk28 = f1;
    self->unk24 = f1;
    self->unk38 = f1;
    self->unk34 = f1;
    self->unk30 = f1;
    self->unk3C = f0;
    self->unk40 = f0;
    self->unk44 = f0;
    if (lbl_805A0110 == 0) {
        fn_8005AD04();
    }
    fn_8005BB58(lbl_805A0110, self);
    return self;
}
