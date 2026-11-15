#include <types.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
gfPadStatus fn_800B9F90(void* a, int flag);
f32 fn_800FAAC8(int stickY, f32 lo, f32 hi);
}

extern const f32 lbl_805A2678;
extern const f32 lbl_805A2680;
extern const f32 lbl_805A2684;
extern const f32 lbl_805A2688;
extern const f32 lbl_805A268C;
extern const f32 lbl_805A2690;

struct Self {
    char _0x0[0x48];
    char m_input[0x8];
    int m_50;
    char _0x54[0x4];
    int m_58;
    char _0x5c[0x9c];
    int m_state;
    f32 m_fc;
    u8 m_flags;
    char _0x101[0x167];
    MuObject* m_mu;
    char _0x26c[0x1138];
    u16 m_13a4;
    char _0x13a6[0x1404];
    u16 m_27aa;
};

static inline f32 lowerClamp(f32 value, f32 lo) {
    return nw4r::math::FSelect(value - lo, value, lo);
}

extern "C" int fn_800F9A14(Self* self) {
    gfPadStatus in = fn_800B9F90(self->m_input, 0);

    if (self->m_state != 0) {
        if (in.m_buttonsPressedThisFrame.bits & 0x100) {
            g_sndSystem->playSE((SndID)(((self->m_flags >> 6) & 1) ? 0x13 : 1), -1, 0, 0, -1);
            return 1;
        }
        if (in.m_buttonsPressedThisFrame.bits & 0x200) {
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            g_sndSystem->playSE((SndID)6, -1, 0, 0, -1);
            switch (self->m_state) {
            case 0:
                break;
            case 1:
                if ((self->m_flags >> 6) & 1) {
                    g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                }
                /* fallthrough */
            case 2:
                self->m_flags = (u8)(self->m_flags & ~0x40);
                self->m_mu->setFrameMatCol(lbl_805A2680);
                break;
            }
            return 1;
        }
    }

    if (self->m_58 & 1) {
        switch (self->m_state) {
        case 0:
            break;
        case 1:
            if (((u32)((self->m_flags >> 6) & 1)) != 1) {
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            /* fallthrough */
        case 2:
            self->m_flags = (u8)(self->m_flags | 0x40);
            self->m_mu->setFrameMatCol(lbl_805A2678);
            break;
        }
    } else if (self->m_58 & 2) {
        switch (self->m_state) {
        case 0:
            break;
        case 1:
            if ((self->m_flags >> 6) & 1) {
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            /* fallthrough */
        case 2:
            self->m_flags = (u8)(self->m_flags & ~0x40);
            self->m_mu->setFrameMatCol(lbl_805A2680);
            break;
        }
    } else if (!(self->m_50 & 3)) {
        f32 speed;
        if (in.m_buttonsCurrentFrame2.bits & 8) {
            speed = lbl_805A2684;
        } else if (in.m_buttonsCurrentFrame2.bits & 4) {
            speed = lbl_805A2688;
        } else {
            speed = fn_800FAAC8(in.m_stickY, lbl_805A2678, lbl_805A2680);
        }
        f32 old = self->m_fc;
        f32 next = old + lbl_805A268C * speed;
        f32 limit = (f32)self->m_27aa - lbl_805A2690;
        self->m_fc = nw4r::math::FSelect(next - limit, limit, next);

        f32 lo = (self->m_13a4 != 0) ? lbl_805A2684 : lbl_805A2678;
        self->m_fc = lowerClamp(self->m_fc, lo);
        if ((s32)old != (s32)self->m_fc) {
            g_sndSystem->playSE((SndID)7, -1, 0, 0, -1);
        }
    }
    return 0;
}
