#include <gm/gm_global.h>
#include <gm/gm_global_mode_melee.h>
#include <gm/gm_global_corps.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern int lbl_1_bss_1A60;
int fn_1_3D1D8(int kind, int color, int player);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
}

extern "C" void fn_1_33C08(void) {
    gmGlobalModeMelee* mode = g_GameGlobal->m_modeMelee;
    int i;
    u8* corps;
    u8* d;
    u8* c;
    int k;
    u8* e;
    int mask;
    unsigned int used;

    if (((u8*)mode)[0x10] != 0x14) {
        i = lbl_1_bss_1A60;
        d = (u8*)mode + i * 0x5C;
        for (; i < 4; d += 0x5C, i++) {
            if (d[0x99] == 1) {
                int temp = fn_1_3D1D8(d[0x98], d[0x9E], i);
                if (temp != d[0x9E]) {
                    int fileNo;
                    int sel;
                    d[0x9E] = temp;
                    sel = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(d[0x98]);
                    if (sel == 0x28) {
                        fileNo = 0;
                    } else {
                        fileNo = getFighterColorFileNo__6muMenuFiii(sel, temp);
                    }
                    d[0x9D] = fileNo;
                }
            }
        }
    }
    if (((u8*)mode)[0x14] == 4) {
        corps = (u8*)g_GameGlobal->m_corps;
        c = corps + 0x24;
        for (k = 0; k < corps[1]; c += 0x14, k++) {
            c[1] = fn_1_3D1D8(c[0], c[1], -1);
        }
    }
    used = 0;
    i = lbl_1_bss_1A60;
    d = (u8*)mode;
    d += i * 0x5C;
    for (int j = i; j < 4; j++, d += 0x5C) {
        if ((s8)d[0xA0] >= 0) {
            used |= 1 << (s8)d[0xA0];
        }
    }
    {
        e = (u8*)mode;
        e += i * 0x5C;
        for (int x = i; x < 4; e += 0x5C, x++) {
            if ((s8)e[0xA0] < 0) {
                for (int b = 0; b < 4; b++) {
                    mask = 1 << b;
                    if ((used & mask) == 0) {
                        e[0xA0] = b;
                        used |= mask;
                        break;
                    }
                }
            }
        }
    }
}