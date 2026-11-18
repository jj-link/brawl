#include <types.h>

#pragma force_active on

extern "C" {
extern const f32 lbl_804094E8[];
extern const f32 lbl_805A295C;
extern const f32 lbl_805A2960;
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
};

struct Inner {
    char p00[8];
    u32 w08;
    char p0C[2];
    u16 h0E;
    char p10[0x4C];
    Object_vptr_0* p5C;
    Object_vptr_0* p60;
    char p64[8];
    u32 w6C;
    u8 b70;
    char p71;
    u8 rest72 : 5;
    u8 x72_5 : 1;
    u8 x72_6 : 1;
    u8 last72 : 1;
    u8 x73_0 : 1;
    u8 rest73 : 7;
    char p74;
    u8 x75_0 : 1;
    u8 x75_1 : 1;
    u8 x75_2 : 1;
    u8 x75_3 : 1;
    u8 x75_4 : 1;
    u8 x75_5 : 1;
    u8 x75_6 : 1;
    u8 x75_7 : 1;
    char p76[0x3E];
    f32 fB4, fB8, fBC, fC0, fC4, fC8, fCC, fD0;
    char pD4[0x30];
    u32 w104, w108, w10C;
    u8 b110;
};

struct Slot {
    u8 b;
    char pad[3];
    f32 f;
    u32 x, y, z;
    u8 flag;
    char pad2[3];
};

struct Self {
    char p00[0x0C];
    u8 bit0C : 1;
    u8 rest0C : 7;
    u8 b0D, b0E, b0F, b10;
    char p11[3];
    u16 h14;
    char p16[2];
    Inner* inner;
    char p1C[4];
    u32 w20;
    char p24[0x10];
    Slot slot[9];
    f32 f10C;
    char p110[0x90];
    u16 h1A0;
    char p1A2[0x126];
    u8 b2C8, b2C9, b2CA, b2CB;
    char p2CC[8];
    f32 f2D4, f2D8;
};

static inline void resetSlot(Slot& slot) {
    slot.f = lbl_805A295C;
    slot.b = 0xff;
    slot.x = 0;
    slot.y = 0;
    slot.z = 0;
    slot.flag = 0;
}

extern "C" void fn_80117D44(Self* self) {
    Inner* in = self->inner;
    self->bit0C = 0;
    self->b0D = 0;
    self->b0F = 0xff;
    self->b10 = 0xff;
    self->h14 = in->h0E;
    self->b0E = 0;

    in->fB4 = lbl_804094E8[0];
    in->fB8 = lbl_804094E8[1];
    in = self->inner;
    in->fBC = lbl_804094E8[2];
    in->fC0 = lbl_804094E8[3];
    in = self->inner;
    in->fC4 = lbl_804094E8[4];
    in->fC8 = lbl_804094E8[5];
    in = self->inner;
    in->fCC = lbl_804094E8[6];
    in->fD0 = lbl_804094E8[7];

    self->inner->p5C->slot18();
    self->inner->p60->slot18();

    self->b0D = 0;
#pragma unroll
    for (int i = 0; i < 8; ++i) {
        resetSlot(self->slot[i]);
    }
    resetSlot(self->slot[8]);

    self->h1A0 = 0;
    self->inner->x72_5 = 0;
    self->inner->x72_6 = 0;
    self->inner->x73_0 = 0;
    self->inner->b70 = 0;

    if (((s32)(self->inner->w08 << 24 |
               ((self->inner->w08 >> 8) & 0x800000)) >> 24) == 1) {
        self->w20 = 1;
    } else {
        self->w20 = 0;
    }

    in = self->inner;
#pragma unroll
    for (int i = 0; i < 8; ++i) {
        resetSlot(self->slot[i]);
    }

    self->b2C8 = 0;
    self->b2C9 = 0;
    self->b2CA = 0;
    self->b2CB = 0;
    self->b0E = 0;

    if (((s32)in->w6C >> 24) != 1) {
        in->x75_1 = 0;
        self->inner->x75_2 = 0;
        self->inner->x75_3 = 0;
        self->inner->x75_4 = 0;
        self->inner->x75_5 = 0;
        self->inner->x75_6 = 0;
        self->inner->x75_7 = 0;
        Inner* current = self->inner;
        if (((s32)current->w08 >> 24) == 2) {
            current->w104 = 0;
            current->w108 = 0;
            current->w10C = 0;
            current->b110 = 0;
            self->inner->x75_0 = 0;
        }
    }

    self->f2D4 = lbl_805A2960;
    self->f2D8 = lbl_805A295C;
    self->f10C = lbl_805A2960;
}
