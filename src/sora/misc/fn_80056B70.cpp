#include <types.h>
#include <gm/gm_global.h>
#include <gm/gm_lib.h>
#pragma force_active on

struct FigureEntry {
    u16 key;
    u16 value;
};

extern "C" {
u32 fn_80052B24(u16 value);
extern FigureEntry lbl_8042DC18[40];
extern FigureEntry lbl_8042DCB8[145];
}

extern "C" void fn_80056B70(void) {
    s32 j;
    s32 jn;
    u32 mask;
    s32 wo;
    s32 i;
    s32 found;
    s32 k;

    for (i = 0, j = 0; i < 0x214; i++, j += 2) {
        wo = (j / 32) * 4;
        mask = 1 << (j % 32);
        jn = j + 1;
        if ((*(u32*)((char*)g_GameGlobal->m_record + 0x15AC + wo) & mask) == 0) {
            found = 0;
            for (k = 0; k < 0x28; k++) {
                if (i == (s32)(lbl_8042DC18[k].key - 1)) {
                    found = 1;
                    if (fn_80052B24(lbl_8042DC18[k].value) == 1) {
                        *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + wo) |= mask;
                        *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + (jn / 32) * 4) |= 1 << (jn % 32);
                    }
                    break;
                }
            }
            if (found == 0) {
                for (k = 0; k < 0x91; k++) {
                    if (i == (s32)(lbl_8042DCB8[k].key - 1)) {
                        found = 1;
                        if (gmCheckExistFigure(lbl_8042DCB8[k].value) == true) {
                            *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + wo) |= mask;
                            *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + (jn / 32) * 4) |= 1 << (jn % 32);
                        }
                        break;
                    }
                }
            }
            if (found == 0) {
                *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + wo) |= mask;
                *(u32*)((char*)g_GameGlobal->m_record + 0x15AC + (jn / 32) * 4) &= ~(1 << (jn % 32));
            }
        }
    }
}
