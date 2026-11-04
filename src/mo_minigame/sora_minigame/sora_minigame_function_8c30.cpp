#pragma force_active on

#include <types.h>
#include <gf/gf_model.h>

extern "C" {
s32 randi__Fl(long);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*, float);
void fn_20_65F0(void*, s32);
extern f32 lbl_20_rodata_130;
extern f32 lbl_20_rodata_138;

struct SoraObj {
    char pad[0x41];
    u8 b41;
    char pad2[0x109 - 0x42];
    u8 b109;
    u8 b10a;
    u8 b10b;
    u8 b10c;
    u8 b10d;
    u8 b10e;
    char pad3[0x370 - 0x10f];
    u8 b370;
};

struct Arg2 {
    char pad[0x2c];
    gfModelAnimation* anim;
};

void fn_20_8C30(SoraObj* self, Arg2* arg2) {
    u8 total;
    if (self->b41 == 0) {
        total = self->b10c + self->b10b + (self->b109 + self->b10a);
    } else {
        setFrame__16gfModelAnimationFd(arg2->anim, lbl_20_rodata_130);
        setUpdateRate__16gfModelAnimationFf(arg2->anim, lbl_20_rodata_138);
        if (self->b370 >= 4) {
            total = self->b10b + (self->b109 + self->b10a);
        } else {
            total = self->b10c + self->b10b + (self->b109 + self->b10a);
        }
    }
    s32 r = randi__Fl(total);
    if (r < self->b109) {
        self->b370 = 1;
    } else if (r < self->b109 + self->b10a) {
        self->b370 = 2;
    } else if (r < self->b10b + (self->b109 + self->b10a)) {
        self->b370 = 3;
    } else {
        self->b370 = self->b10d + randi__Fl(self->b10e - self->b10d);
    }
    fn_20_65F0(arg2, 0);
}
}
