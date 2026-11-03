#include <types.h>
#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" int fn_8004D740(GameGlobal* global);
extern "C" int fn_8004D6C4(GameGlobal* global, int index, char* out);
extern "C" char* fn_800B96B0(void);
extern "C" char lbl_16_data_3564[];

const u8 lbl_16_rodata_198[112] = {
    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00,
    0x19, 0x19, 0x19, 0x00, 0x19, 0x19, 0x19, 0x00,
    0x19, 0x19, 0x19, 0x00, 0x19, 0x19, 0x19, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x77, 0x07, 0x03, 0x00,
    0x77, 0x07, 0x03, 0x00, 0x77, 0x07, 0x03, 0x00,
    0x19, 0x19, 0x19, 0x00, 0x77, 0x07, 0x03, 0x00,
    0x77, 0x07, 0x03, 0x00, 0x77, 0x07, 0x03, 0x00,
    0x8a, 0x8a, 0x8a, 0x00, 0x8a, 0x8a, 0x8a, 0x00,
    0x8a, 0x8a, 0x8a, 0x00, 0x8a, 0x8a, 0x8a, 0x00,
    0xc8, 0xc8, 0xc8, 0x00, 0xc8, 0xc8, 0xc8, 0x00,
    0xc8, 0xc8, 0xc8, 0x00, 0xc8, 0xc8, 0xc8, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00,
};

struct MsgEntry {
    u8 flags;
    u8 pad1;
    s16 id;
};

extern "C" void fn_16_32E8(u8* self, s32 msgIndex, s32 start) {
    char buf[0x20];
    s32 sel;
    MsgEntry* entry = (MsgEntry*)(self + 0x1F0 + ((u16)start << 2));
    s32 j = 0;
    s32 i = start;
    u16 count = *(u16*)(self + 0x3D8);
    for (; j < 5; j++) {
        if (i < count) {
            sel = -1;
            if ((u16)(entry->id + 2) > 1) {
                sel = entry->id;
            }
            s32 state;
            if (sel != -1) {
                if (!((entry->flags >> 7) & 1)) {
                    if (j != msgIndex) {
                        state = 0;
                    } else {
                        state = 1;
                    }
                } else if (j != msgIndex) {
                    state = 5;
                } else {
                    state = 6;
                }
            } else if (fn_8004D740(g_GameGlobal) > 0) {
                if (j != msgIndex) {
                    state = 2;
                } else {
                    state = 3;
                }
            } else {
                state = 4;
            }
            const u8* color = lbl_16_rodata_198 + (state << 4) + (*(s32*)(self + 0x98) << 2);
            ((MuMsg*)*(void**)(self + 0x154))->setFontColor(j, color[0], color[1], color[2], 0xFF);
            if (sel == -1) {
                ((MuMsg*)*(void**)(self + 0x154))->printf(j, fn_800B96B0());
            } else {
                fn_8004D6C4(g_GameGlobal, sel, buf);
                ((MuMsg*)*(void**)(self + 0x154))->printf(j, buf);
            }
        } else {
            ((MuMsg*)*(void**)(self + 0x154))->printf(j, lbl_16_data_3564);
        }
        entry++;
        i++;
    }
}
