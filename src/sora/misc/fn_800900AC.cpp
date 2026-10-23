#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_8059DC08;
extern const f32 lbl_805A1CA8;
}

struct Vec {
    f32 x, y, z;
};

struct State {
    u8 pad0[4];
    s32 count;
    u8 pad8[6];
    u8 flagE;
    u8 padF[0x11];
    u8 flag20;
    u8 pad21[0x1F];
    u8 flag40, flag41, index42, flag43;
    Vec vec44;
    f32 value50;
    u8 pad54[2];
    u8 flag56, flag57, flag58, flag59, flag5A, flag5B;
};

extern "C" void fn_800900AC(State* self, const Vec* v, s32 a, s32 b) {
    self->flag40 = 1;
    self->flag41 = 0;
    self->vec44 = *v;

    if (a > self->count - 1) {
        self->index42 = self->count - 1;
    } else {
        self->index42 = a;
    }

    self->flag43 = 0;
    self->value50 = lbl_805A1CA8;
    self->flag57 = 0;
    self->flag58 = 0;
    self->flag59 = 0;
    self->flag5A = 0;
    self->flag5B = b;

    if (self->vec44.x < lbl_805A1CA8) {
        self->flag56 = 1;
    } else {
        self->flag56 = 0;
    }

    if (self->flag20 == 0 && lbl_8059DC08 != 0) {
        self->flagE = 1;
    }
    self->flag20 = lbl_8059DC08;
}
