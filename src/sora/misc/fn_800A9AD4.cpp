#pragma force_active on

#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <nw4r/math/math_arithmetic.h>

struct StickResult {
    f32 x;
    f32 y;
};

struct PadOutput {
    u8 buttonMask;
    u8 pad[3];
    f32 x;
    f32 y;
};

struct PadMatchSub {
    u32 mask;
    u8 flags;
    u8 padding[3];
};

struct PadMatchEntry {
    u8 typeFlag;
    u8 resultMask;
    u8 pad[2];
    PadMatchSub sub[4];
};

extern const PadMatchEntry lbl_804079C0[3];
extern const f32 lbl_805A20FC;
extern const f32 lbl_805A212C;

extern "C" StickResult fn_800A9C7C(int, gfPadStatus*);

inline bool matchesPad(u32 source, const PadMatchSub& sub) {
    u32 matchedBits = source & sub.mask;
    if (((sub.flags >> 7) & 1) == 0) {
        if (matchedBits != 0) {
            return true;
        }
    } else if (matchedBits == sub.mask) {
        return true;
    }
    return false;
}

inline u8 getPadMask(const gfPadStatus* pad) {
    u8 mask = 0;
    u32 current;
    u32 pressed;
    pressed = pad->m_buttonsPressedThisFrame.bits;
    current = pad->m_buttonsCurrentFrame2.bits;
    u32 controllerOffset = pad->m_controllerType * 8;
    const PadMatchEntry* entry;
    const PadMatchEntry* mapping;
    mapping = lbl_804079C0;
    entry = mapping;

    for (int j = 0; j < 3; j++, mapping++, entry++) {
        const PadMatchSub& sub =
            *(const PadMatchSub*)((const char*)mapping + controllerOffset + 4);
        u32 source = current;

        if (entry->typeFlag != 0) {
            source = pressed;
        }

        if (matchesPad(source, sub)) {
            mask |= entry->resultMask;
        }
    }

    return mask;
}

inline int isStickEmpty(PadOutput* self, f32 threshold) {
    int update = 0;
    int test = 0;

    if ((f32)(double)nw4r::math::FAbs(self->x) < threshold) {
        test = 1;
    }

    if (test != 0) {
        int secondTest = 0;
        if ((f32)(double)nw4r::math::FAbs(self->y) < threshold) {
            secondTest = 1;
        }
        if (secondTest != 0) {
            update = 1;
        }
    }

    return update;
}

extern "C" void fn_800A9AD4(PadOutput* self, int arg1) {
    self->buttonMask = 0;
    f32 threshold = lbl_805A212C;
    self->y = lbl_805A20FC;
    self->x = lbl_805A20FC;

    for (int i = 0; i < 8; i++) {
        gfPadStatus pad;
        g_gfPadSystem->getSysPadStatus(i, &pad);

        if (pad.m_error == 0) {
            if (isStickEmpty(self, threshold)) {
                StickResult result = fn_800A9C7C(arg1, &pad);
                self->x = result.x;
                self->y = result.y;
            }

            self->buttonMask |= getPadMask(&pad);
        }
    }
}
