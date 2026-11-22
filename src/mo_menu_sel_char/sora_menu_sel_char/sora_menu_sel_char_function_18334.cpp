#include <types.h>
#include <gm/gm_global.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#pragma force_active on

struct SelObjB {
    char pad[0x5cc];
    int f5cc;
    unsigned char f5d0;
};
struct SelSelf {
    char pad0[0xd4];
    MuObject* md4;
    char padd8[0x1d0 - 0xd8];
    int m1d0;
    char pad1d4[0x1f4 - 0x1d4];
    SelObjB* m1f4;
    char pad1f8[4];
    char m1fc[4];
};
extern "C" int fn_10_1D5C4(void*, gfPadStatus*, int*);
extern "C" void fn_10_1DE50(void*);

static inline void copyPad(gfPadStatus& d, const gfPadStatus& s) {
 d.m_buttonsCurrentFrame = s.m_buttonsCurrentFrame;
 d.m_buttonsCurrentFrame2 = s.m_buttonsCurrentFrame2;
 d.m_buttonsHeld = s.m_buttonsHeld;
 d.m_buttonsPressedThisFrame = s.m_buttonsPressedThisFrame;
 d.m_buttonsReleasedThisFrame = s.m_buttonsReleasedThisFrame;
 d.m_buttonsPressedThisFrame2 = s.m_buttonsPressedThisFrame2;
 d._0x18 = s._0x18; d._0x1c = s._0x1c; d._0x20 = s._0x20;
 d._0x24 = s._0x24; d._0x28 = s._0x28; d._0x2c = s._0x2c;
 d.m_stickX = s.m_stickX; d.m_stickY = s.m_stickY;
 d.m_subStickX = s.m_subStickX; d.m_subStickY = s.m_subStickY;
 d.m_lTriggerAnalog = s.m_lTriggerAnalog; d.m_rTriggerAnalog = s.m_rTriggerAnalog;
 d._0x36 = s._0x36; d._0x37 = s._0x37; d.m_error = s.m_error;
 d.m_controllerType = s.m_controllerType;
}

static inline int getMode(SelSelf* self) {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 1) return 0;
    SelObjB* p = self->m1f4;
    if (p->f5d0 != 0) return 2;
    return p->f5cc == 2;
}

static inline void setFrames(MuObject* obj, int f) {
    obj->setFrameTex((float)f);
    obj->setFrameNode((float)f);
    obj->setFrameMatCol((float)f);
}

extern "C" int fn_10_18334(SelSelf* self, const gfPadStatus* in, const gfPadStatus* in2) {
    gfPadStatus p;
    copyPad(p, *in);
    p.m_buttonsCurrentFrame2 = in2->m_buttonsHeld;
    p.m_buttonsPressedThisFrame = in2->m_buttonsPressedThisFrame;
    p.m_buttonsPressedThisFrame2 = in2->m_buttonsReleasedThisFrame;
    int frame;
    int ret = 0;
    switch (fn_10_1D5C4(self->m1fc, &p, &frame)) {
    case 2:
        if (getMode(self) == 1) {
            int f = frame;
            setFrames(self->md4, f);
            self->m1d0 = f;
        } else {
            int f = frame;
            self->m1d0 = f;
            setFrames(self->md4, f);
        }
        ret = 1;
        break;
    case 1:
        break;
    }
    if (ret != 0) fn_10_1DE50(self->m1fc);
    return ret;
}
