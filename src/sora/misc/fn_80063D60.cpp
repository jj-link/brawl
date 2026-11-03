#include <types.h>
#include <gf/gf_model.h>
#pragma force_active on

struct ModelOwner {
    char pad[0x3C];
    s32 m_state;
    char pad2[0x8];
    gfModelAnimation* m_anim;
};

extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation* anim, double frame);

extern "C" void fn_80063D60(ModelOwner* self, u32 flags, float frame) {
    gfModelAnimation* anim = self->m_anim;
    if (anim == NULL) {
        return;
    }
    if ((u8)flags == 0xFF) {
        setFrame__16gfModelAnimationFd(anim, frame);
    } else {
        if (flags & 1) {
            nw4r::g3d::AnmObjChrRes* o = anim->m_anmObjChrRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
        if (flags & 2) {
            nw4r::g3d::AnmObjVisRes* o = self->m_anim->m_anmObjVisRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
        if (flags & 4) {
            nw4r::g3d::AnmObjTexPatRes* o = self->m_anim->m_anmObjTexPatRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
        if (flags & 8) {
            nw4r::g3d::AnmObjTexSrtRes* o = self->m_anim->m_anmObjTexSrtRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
        if (flags & 0x10) {
            nw4r::g3d::AnmObjMatClrRes* o = self->m_anim->m_anmObjMatClrRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
        if (flags & 0x20) {
            nw4r::g3d::AnmObjShpRes* o = self->m_anim->m_anmObjShpRes;
            if (o != NULL) {
                o->SetFrame(frame);
            }
        }
    }
    self->m_state = -1;
}
