#include <types.h>
#pragma force_active on

struct LinkNodeBits {
    u32 hi : 3;
    u32 mid : 16;
    u32 lo : 13;
};

struct LinkNodeInit {
    s32 unk0;
    s32 unk4;
    union {
        u32 unk8;
        LinkNodeBits bits;
    } f8;
    s16 unkC;
    s16 unkE;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
};

extern "C" {
extern char lbl_8049DEDC[];
extern const float lbl_805A1E30;
extern const float lbl_805A1E38;
extern const float lbl_805A1E3C;
extern const float lbl_805A1E40;
extern const float lbl_805A1E44;
extern const float lbl_805A1E48;
extern const float lbl_805A1E4C;
extern const float lbl_805A1E50;
extern const float lbl_805A1E54;

void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

struct LinkNodeInit* fn_8009ED40(struct LinkNodeInit* self, s32 arg1, u32 arg2) {
    u32 flags;
    void* it;

    self->f8.bits.hi = arg1;
    self->f8.bits.mid = 0;
    flags = self->f8.unk8;
    self->unk0 = 0;
    self->unk4 = 0;
    self->f8.unk8 = flags;
    self->unkC = 0;
    self->unkE = 0;
    self->unk10 = lbl_805A1E30;
    self->unk14 = lbl_805A1E30;
    self->unk18 = lbl_805A1E30;
    self->unk1C = lbl_805A1E30;
    self->unk20 = lbl_805A1E30;
    self->unk24 = lbl_805A1E30;
    self->unk28 = lbl_805A1E30;
    self->unk60 = lbl_805A1E30;
    self->unk64 = lbl_805A1E30;
    self->unk68 = lbl_805A1E30;
    self->unk2C = lbl_805A1E38;
    self->unk30 = lbl_805A1E3C;
    self->unk34 = lbl_805A1E3C;
    self->unk38 = lbl_805A1E38;
    self->unk4C = lbl_805A1E30;
    self->unk50 = lbl_805A1E30;
    self->unk54 = lbl_805A1E30;
    self->unk58 = lbl_805A1E30;
    self->unk3C = lbl_805A1E38;
    self->unk40 = lbl_805A1E3C;
    self->unk44 = lbl_805A1E3C;
    self->unk48 = lbl_805A1E38;
    self->unk5C = lbl_805A1E30;
    self->unk6C = lbl_805A1E40;
    self->unk70 = lbl_805A1E44;
    self->unk74 = lbl_805A1E48;
    self->unk78 = lbl_805A1E4C;
    self->unk7C = lbl_805A1E50;
    self->unk80 = lbl_805A1E54;
    if (arg2 == 1U && !((flags >> 13) & 1)) {
        it = lbl_8049DEDC + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(lbl_8049DEDC, &it, self);
        self->f8.unk8 |= 0x2000;
    }
    return self;
}
}
