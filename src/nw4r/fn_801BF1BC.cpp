#include <types.h>
#pragma force_active on

extern const f32 lbl_805A34EC;
extern const f32 lbl_805A34F0;
extern f64 lbl_805A34F8;
extern s16 lbl_8040AC30[];

struct Obj {
    s32 state;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
};

extern "C" void fn_801BF1BC(Obj* self, s32 n) {
    f32 c;
    s32 i;
    switch (self->state) {
    case 0:
        for (i = n; i > 0; i--) {
            f32 t;
            n--;
            t = self->unk4 * self->unk10;
            self->unk4 = t;
            if (t > lbl_805A34F0) {
                self->unk4 = lbl_805A34EC;
                self->state = 1;
            }
        }
        if (self->state != 1) {
            return;
        }
        /* fall through */
    case 1:
        c = (f32)lbl_8040AC30[self->unk14];
        self->unk4 = self->unk4 - self->unk8 * (f32)n;
        if (!(self->unk4 > c)) {
            self->unk4 = c;
            self->state = 2;
        }
        break;
    case 3:
        self->unk4 = self->unk4 - self->unkC * (f32)n;
        break;
    }
}
