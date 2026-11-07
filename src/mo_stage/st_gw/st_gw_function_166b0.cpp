#include <nw4r/math/math_arithmetic.h>
#include <nw4r/g3d/g3d_resnode.h>
#include <types.h>
#pragma force_active on

extern const float lbl_63_rodata_224;
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* mdl, u32 idx);

struct ResObj {
    char pad[0xE8];
    s32 fe8;
};

struct GrObj {
    char pad0[0x44];
    ResObj** f44;
    char padA[0xC4 - 0x48];
    u32 fc4;
    char padB[0x1B4 - 0xC8];
    f32 f1b4;
    f32 f1b8;
    f32 f1bc;
};

extern "C" void fn_63_166B0(GrObj* self) {
    s32 sp8;
    s32 r5 = 0;
    s32 r0 = 0;
    if ((float)(double)nw4r::math::FAbs(self->f1b4) < lbl_63_rodata_224) {
        r0 = 1;
    }
    if (r0 != 0) {
        r0 = 0;
        if ((float)(double)nw4r::math::FAbs(self->f1b8) < lbl_63_rodata_224) {
            r0 = 1;
        }
        if (r0 != 0) {
            r0 = 0;
            if ((float)(double)nw4r::math::FAbs(self->f1bc) < lbl_63_rodata_224) {
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
                nw4r::g3d::ResNodeData* node = (nw4r::g3d::ResNodeData*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, self->fc4);
                if (node != 0) {
                    self->f1b4 = node->m_scale.m_x;
                    self->f1b8 = node->m_scale.m_y;
                    self->f1bc = node->m_scale.m_z;
                }
            }
        }
    }
}