#include <types.h>
#include <gf/gf_model.h>
#pragma force_active on

extern float lbl_805A1958;

struct Owner {
    u8 pad0[0x48];
    gfModelAnimation* anim;
    u8 pad1[0x56 - 0x4C];
    u16 flags;
};

extern "C" void fn_80063AF4(Owner* self, int arg1, u32 arg2) {
    if (self->anim == NULL) {
        return;
    }
    if ((u8)arg2 == 0xFF) {
        if (arg1 != 0) {
            self->flags &= ~0x7E;
        } else {
            self->anim->setUpdateRate(lbl_805A1958);
            self->flags |= 0x7E;
        }
        return;
    }
    if (arg2 & 1) {
        nw4r::g3d::AnmObjChrRes* obj = self->anim->m_anmObjChrRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x2;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x2;
            }
        }
    }
    if (arg2 & 2) {
        nw4r::g3d::AnmObjVisRes* obj = self->anim->m_anmObjVisRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x4;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x4;
            }
        }
    }
    if (arg2 & 4) {
        nw4r::g3d::AnmObjTexPatRes* obj = self->anim->m_anmObjTexPatRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x8;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x8;
            }
        }
    }
    if (arg2 & 8) {
        nw4r::g3d::AnmObjTexSrtRes* obj = self->anim->m_anmObjTexSrtRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x10;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x10;
            }
        }
    }
    if (arg2 & 0x10) {
        nw4r::g3d::AnmObjMatClrRes* obj = self->anim->m_anmObjMatClrRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x20;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x20;
            }
        }
    }
    if (arg2 & 0x20) {
        nw4r::g3d::AnmObjShpRes* obj = self->anim->m_anmObjShpRes;
        if (obj != NULL) {
            if (arg1 != 0) {
                self->flags &= ~0x40;
            } else {
                obj->SetUpdateRate(lbl_805A1958);
                self->flags |= 0x40;
            }
        }
    }
}
