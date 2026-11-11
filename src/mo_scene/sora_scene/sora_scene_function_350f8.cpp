#include <types.h>
#include <gm/gm_global.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on
extern "C" {
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_1_350F8() {
    int costume;
    GameGlobal* gg = g_GameGlobal;
    unsigned char* dest = (unsigned char*)gg->m_modeMelee;
    unsigned char* src = (unsigned char*)gg->m_selCharData;
    unsigned char* d = dest;
    int i = 0;
    int minusone = -1;
    int zero = 0;
    for (; i < 4; i++) {
        int kind = src[0xb8];
        d[0x98] = kind;
        d[0x99] = src[0xb9];
        d[0xa3] = zero;
        costume = src[0xbd];
        int m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
        int color;
        if (m == 0x28) {
            color = 0;
        } else {
            color = getFighterColorFileNo__6muMenuFiii(m, costume);
        }
        d[0x9d] = color;
        d[0x9e] = src[0xbd];
        d[0xb0] = src[0xd0];
        d[0x9f] = src[0xbf];
        d[0x9a] = i;
        *((signed char*)(d + 0x9c)) = -1;
        src += 0x5c;
        d += 0x5c;
    }
    ((gmGlobalModeMelee*)dest)->m_meleeInitData.m_isTeamAttack = false;
    ((gmGlobalModeMelee*)dest)->m_meleeInitData.m_numPlayers = 3;
}
}
