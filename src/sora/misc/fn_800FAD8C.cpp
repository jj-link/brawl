#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>

#pragma force_active on

struct PadMatchPair {
    u32 value;
    u32 mask;
};

struct PadMatchEntry {
    u8 flag;
    u8 _pad[3];
    PadMatchPair def;
    PadMatchPair ctype2;
    PadMatchPair ctype3;
};

extern PadMatchEntry lbl_8045C158[9];

struct PadCheckSource {
    u8 _0x0[4];
    u8 unk4;
    u8 _pad5[0x17];
    u32 unk1C;
};

extern "C" u32 fn_800FAD8C(PadCheckSource* arg0) {
    gfPadStatus sp8;
    u32 result = 0;
    u32 mask = arg0->unk4;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            g_gfPadSystem->getSysPadStatus(i, &sp8);
            u32 bit = 1;
            for (s32 j = 0; j < 9; j++) {
                PadMatchEntry* e = &lbl_8045C158[j];
                PadMatchPair* p;
                u32 pressed;
                switch (sp8.m_controllerType) {
                case 1:
                default:
                    p = &e->def;
                    break;
                case 2:
                    p = &e->ctype2;
                    break;
                case 3:
                    p = &e->ctype3;
                    break;
                }
                if (e->flag != 0)
                    pressed = sp8.m_buttonsPressedThisFrame2.bits;
                else
                    pressed = sp8.m_buttonsPressedThisFrame.bits;
                if (p->value == (sp8.m_buttonsCurrentFrame2.bits & ~p->mask)) {
                    if (pressed != 0 && (pressed & ~p->mask) == 0) {
                        result |= bit;
                    }
                }
                bit <<= 1;
            }
        }
    }

    if (arg0->unk1C & 5) {
        result |= 0x80;
    } else if (arg0->unk1C & 0xA) {
        result |= 0x100;
    }
    return result;
}