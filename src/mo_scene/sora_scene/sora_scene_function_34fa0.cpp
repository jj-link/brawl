#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Byte9 {
    u8 a : 3;
    u8 f : 3;
    u8 b : 2;
};

extern "C" {
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);

static inline void collectActive(int* out, u8* src, int& j) {
    for (j = 0; j < 4; j++) {
        if (src[0xb9 + j * 0x5c] != 3) {
            *out++ = j;
        }
    }
}

void fn_1_34FA0(int* arg0) {
    int sp[4];
    u8* src;
    u8* dest;
    u8* s;
    u8 kind;
    u8 costume;
    int ch;
    int sel;
    u8* d;
    int i;
    int flag;
    int* p = sp;

    src = (u8*)g_GameGlobal->m_selCharData;
    dest = (u8*)g_GameGlobal->m_modeMelee;

    int j;
    collectActive(p, src, j);

    sel = sp[arg0[6]];
    d = dest;
    s = src;
    for (i = 0; i < 4; i++) {
        kind = s[0xb8];
        d[0x98] = kind;
        d[0x99] = s[0xb9];
        d[0xa3] = s[0xc3];
        costume = s[0xbd];

        ch = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
        d[0x9d] = ch == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(ch, costume);

        flag = ~((i - sel) | (sel - i)) >> 31;
        d[0x9e] = s[0xbd];
        d[0xb0] = s[0xd0];
        d[0x9f] = s[0xbf];
        d[0x9a] = i;
        d[0x9c] = flag;
        s += 0x5c;
        d += 0x5c;
    }

    *(int*)(dest + 0x68) = arg0[6];
    *(int*)(dest + 0x6c) = arg0[8];
    ((Byte9*)(dest + 9))->f = 2;
}
}
