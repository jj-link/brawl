#include <nw4r/math/math_arithmetic.h>
#include <nw4r/g3d/g3d_resnode.h>
#include <types.h>
#pragma force_active on

extern const float lbl_46_rodata_D4;
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* mdl, u32 idx);

struct ResObj {
    char pad[0xE8];
    s32 fe8;
};

struct Obj46 {
    char pad0[0x44];
    ResObj** f44;
    char padA[0xC4 - 0x48];
    u32 fc4;
    char padB[0x158 - 0xC8];
    f32 f158;
    f32 f15c;
    f32 f160;
};

extern "C" void fn_46_4630(Obj46* self) {
    s32 sp8;
    s32 r5 = 0;
    s32 r0 = 0;
    if ((float)(double)nw4r::math::FAbs(self->f158) < lbl_46_rodata_D4) {
        r0 = 1;
    }
    if (r0 != 0) {
        r0 = 0;
        if ((float)(double)nw4r::math::FAbs(self->f15c) < lbl_46_rodata_D4) {
            r0 = 1;
        }
        if (r0 != 0) {
            r0 = 0;
            if ((float)(double)nw4r::math::FAbs(self->f160) < lbl_46_rodata_D4) {
                r0 = 1;
            }
            if (r0 != 0) {
                r5 = 1;
            }
        }
    }
    if (r5 != 0) {
        sp8 = 0;
        ResObj* p = *self->f44;
        if (p != 0) {
            sp8 = p->fe8;
            if (sp8 != 0) {
                struct RN { char pad[0x20]; f32 x; f32 y; f32 z; };
                RN* node = (RN*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, self->fc4);
                if (node != 0) {
                    self->f158 = node->x;
                    self->f15c = node->y;
                    self->f160 = node->z;
                }
            }
        }
    }
}
