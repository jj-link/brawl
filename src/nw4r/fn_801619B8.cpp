#include <types.h>
#pragma force_active on

struct U2 {
    u32 a;
    u32 b;
};

struct Obj {
    u8 b00, b01, b02, b03, b04, b05, b06, b07;
    u8 b08, b09, b0A, b0B, b0C, b0D, b0E, b0F;
    u8 b10, b11, b12, b13, b14, b15, b16, b17;
    u8 b18, b19, b1A, b1B, b1C, b1D, b1E, b1F;
    u32 w20;
    U2 p24;
    U2 p2C;
    u32 w34;
    U2 p38;
    u8 b40[4];
    f32 f44;
    u32 w48;
    f32 f4C;
    f32 f50;
    f32 f54;
    u32 w58;
    u32 w5C;
    u32 w60;
};

extern "C" {
void* fn_8015ECB8(void*, int);
void fn_80160E3C(void*, f32*, s32, s32);
void fn_801607B4(void*, f32*, s32*, s32, f32);
f32 fn_8015F8D4(void*);
}

extern f32 lbl_805A2BDC;
extern f32 lbl_805A2BE8;

extern "C" f32 fn_801619B8(Obj* self, f32* p1, f32* p2, s32 a3, s32 a4) {
    Obj tmp0;
    Obj tmpA;
    Obj tmpB;
    f32 sp30[4];
    f32 sp20[4];
    f32 sp10[4];
    s32 spC;
    s32 sp8;
    f32 varF31;
    f32 varF2;
    f32 f30;
    f32 d;
    u32 t;
    u32 m;

    varF31 = lbl_805A2BDC;
    varF2 = varF31;
    t = self->w5C & 0x333;
    if (t != 0x300 && t != 0) {
        sp30[0] = lbl_805A2BDC;
        sp30[1] = lbl_805A2BDC;
        sp30[2] = lbl_805A2BDC;
        sp30[3] = lbl_805A2BDC;
        tmp0.f4C = tmp0.f4C;
        tmp0 = *self;
        fn_80160E3C(&tmp0, sp30, a3, a4);
        fn_8015ECB8(&tmp0, 0);
        varF31 = sp30[0] + sp30[2];
        varF2 = sp30[1] + sp30[3];
        if (varF31 > *(f32*)&self->f4C) {
            varF31 = *(f32*)&self->f4C;
        }
    }

    m = self->w5C & 0x30;
    if (m == 0x10) {
        *p1 -= varF31 * lbl_805A2BE8;
    } else if (m == 0x20) {
        *p1 -= varF31;
    }

    m = self->w5C & 0x300;
    if (m == 0x100) {
        *p2 -= varF2 * lbl_805A2BE8;
    } else if (m == 0x200) {
        *p2 -= varF2;
    }

    m = self->w5C & 3;
    if (m == 1) {
        spC = a3;
        sp20[0] = lbl_805A2BDC;
        sp20[1] = lbl_805A2BDC;
        sp20[2] = lbl_805A2BDC;
        sp20[3] = lbl_805A2BDC;
        *(f32*)&tmpA.p2C.a = *(f32*)&tmpA.p2C.a;
        tmpA = *self;
        *(f32*)&tmpA.p2C.a = lbl_805A2BDC;
        *(f32*)&tmpA.p2C.b = lbl_805A2BDC;
        fn_801607B4(&tmpA, sp20, &spC, a4, lbl_805A2BDC);
        f30 = sp20[2] - sp20[0];
        fn_8015ECB8(&tmpA, 0);
        d = varF31 - f30;
        *(f32*)&self->p2C.a = *p1 + d * lbl_805A2BE8;
    } else if (m == 2) {
        sp8 = a3;
        sp10[0] = lbl_805A2BDC;
        sp10[1] = lbl_805A2BDC;
        sp10[2] = lbl_805A2BDC;
        sp10[3] = lbl_805A2BDC;
        *(f32*)&tmpB.p2C.a = *(f32*)&tmpB.p2C.a;
        tmpB = *self;
        *(f32*)&tmpB.p2C.a = lbl_805A2BDC;
        *(f32*)&tmpB.p2C.b = lbl_805A2BDC;
        fn_801607B4(&tmpB, sp10, &sp8, a4, lbl_805A2BDC);
        f30 = sp10[2] - sp10[0];
        fn_8015ECB8(&tmpB, 0);
        *(f32*)&self->p2C.a = *p1 + (varF31 - f30);
    } else {
        *(f32*)&self->p2C.a = *p1;
    }

    if ((self->w5C & 0x300) == 0x300) {
        *(f32*)&self->p2C.b = *p2;
    } else {
        *(f32*)&self->p2C.b = *p2 + fn_8015F8D4(self);
    }
    return varF31;
}
