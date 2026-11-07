#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {

extern unsigned char lbl_10_rodata_568[];
int isTeamBattle__19muSelCharPlayerAreaFv(void* self);
int getCharColorNo__6muMenuFiii(int, int);
int exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getNumCharColor__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_800CA498(void*, int, int, int);

struct SelArea {
    int f0;
    char pad4[0x1ac];
    int f1b0;
    char pad1b4[4];
    int f1b8;
    int f1bc;
    int f1c0;
    char pad1c4[0x24];
    int f1e8;
    int f1ec;
    int f1f0;
    char pad1f4[0x21c];
    int f410;
    int f414;
    int f418;
    char pad41c[0x28];
    unsigned char f444;
    unsigned char f445;
};

static inline int getMode(int state) {
    int result;
    if (state >= 0 && state < 4)
        result = 1;
    else
        result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc)
            result = 1;
        else
            result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10)
                r0_4 = 1;
            else
                r0_4 = 0;
            result = 3;
            if (r0_4 != 0)
                result = 2;
        }
    }
    return result;
}

void fn_10_13CAC(SelArea* self) {
    const unsigned char* const base = lbl_10_rodata_568;
    const unsigned char* tbl;
    int kind = self->f1b8;
    switch (kind) {
    case 14:
        tbl = base;
        tbl = (const unsigned char*)((unsigned int)tbl + 0x18);
        kind = tbl[self->f1e8];
        break;
    case 3:
        tbl = base;
        tbl = (const unsigned char*)((unsigned int)tbl + 0x1c);
        kind = tbl[self->f1ec];
        break;
    case 27:
        tbl = base;
        tbl = (const unsigned char*)((unsigned int)tbl + 0x20);
        kind = tbl[self->f1f0];
        break;
    }
    if (kind == 0x28)
        return;
    int color = self->f1bc;
    if (kind == 0x29) {
        kind = self->f410;
        color = self->f414;
    }
    if (isTeamBattle__19muSelCharPlayerAreaFv(self)) {
        tbl = base;
        tbl = (const unsigned char*)((unsigned int)tbl + 0x48);
        color = getCharColorNo__6muMenuFiii(kind, tbl[self->f1c0]);
    }
    if (kind == 0x1b) {
        tbl = base;
        tbl = (const unsigned char*)((unsigned int)tbl + 0x20);
        kind = tbl[self->f418];
    }
    if (self->f0 != 0)
        return;
    int gm = exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(kind);
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int flag;
    if (getMode(state) == 0 || getMode(state) == 1)
        flag = 0;
    else
        flag = 1;
    if (flag && gm != 0x3e) {
        fn_800CA498(g_muWifiInterfaceTask, self->f1b0, gm, color);
    }
    if (gm == 0x3e)
        return;
    int fileNo = 0;
    int m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(gm);
    int num = (m == 0x28) ? 1 : getNumCharColor__6muMenuFiii(m);
    if (color < num) {
        int m2 = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(gm);
        fileNo = (m2 == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(m2, color);
    }
    self->f444 = gm;
    self->f445 = fileNo;
}
}
