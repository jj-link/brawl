#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on

extern f32 lbl_805A2850;
extern f32 lbl_805A2854;

struct IP {
    int a;
    u32 b;
    bool test() const { return a == 0 && b >= 1; }
};

struct Self {
    char _0[0xE8];
    MuObject* object;
    char _EC[0x2C];
    IP p1;
    IP p2;
};

struct Pair {
    union {
        bool b;
        u32 i;
    } first;
    u32 second;
};

struct Holder {
    gfPadStatus s;
};

static inline u32 g0(gfPadStatus s) { return s.m_buttonsCurrentFrame.bits; }
static inline u32 g1(gfPadStatus s) { return s.m_buttonsCurrentFrame2.bits; }
static inline u32 g2(gfPadStatus s) { return s.m_buttonsHeld.bits; }
static inline u32 g3(gfPadStatus s) { return s.m_buttonsPressedThisFrame.bits; }
static inline u32 g4(gfPadStatus s) { return s.m_buttonsReleasedThisFrame.bits; }
static inline u32 g5(gfPadStatus s) { return s.m_buttonsPressedThisFrame2.bits; }

static inline void process(gfPadStatus s) {
    Holder h;
    h.s = s;
    g0(h.s); g1(h.s); g2(h.s); g3(h.s); g4(h.s); g5(h.s);
}

extern "C" void fn_8010A968(Self* self) {
    gfPadStatus status;
    self->p2.a = 1;
    self->p2.b = 1;
    int pa;
    u32 pb;
    switch (self->p2.a) {
    default:
        break;
    case 1:
        pb = 0x80;
        pa = 0;
        break;
    }
    self->p1.a = pa;
    self->p1.b = pb;
    float frame;
    if (self->p1.test() || self->p2.test())
        frame = lbl_805A2850;
    else
        frame = lbl_805A2854;
    self->object->setFrameVisible(frame);

    Pair tmp, pair;
    if (g_GameGlobal->m_advData) {
        pair.first.i = *(u32*)((char*)g_GameGlobal->m_advData + 0x4928);
        pair.second = *(u32*)((char*)g_GameGlobal->m_advData + 0x492C);
    } else {
        tmp.first.b = false;
        tmp.second = -1;
        pair = tmp;
    }
    Pair other = pair;
    g_gfPadSystem->getSysPadStatus(other.second, &status);
    process(status);
}
