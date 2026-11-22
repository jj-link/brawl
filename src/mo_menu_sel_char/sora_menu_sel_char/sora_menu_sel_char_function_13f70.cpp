#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {

int exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getNumCharColor__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_800CA498(void*, int, int, int);
void fn_1_379C(int, int, int);

struct SelArea {
    int f0;
    char pad4[0x1ac];
    int f1b0;
    char pad1b4[0x290];
    unsigned char f444;
    unsigned char f445;
    unsigned char f446;
    unsigned char f447;
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

void fn_10_13F70(SelArea* self, int kind, int color, int character) {
    int input = kind;
    kind = color;
    color = character;
    if (self->f0 != 0)
        return;
    character = exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(input);
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int flag;
    if (getMode(state) == 0 || getMode(state) == 1)
        flag = 0;
    else
        flag = 1;
    if (flag && character != 0x3e)
        fn_800CA498(g_muWifiInterfaceTask, self->f1b0, character, kind);
    if (character == 0x3e)
        return;
    int fileNo = 0;
    int m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(character);
    int num = (m == 0x28) ? 1 : getNumCharColor__6muMenuFiii(m);
    if (kind < num) {
        int m2 = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(character);
        fileNo = (m2 == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(m2, kind);
    }
    self->f444 = (unsigned char)character;
    self->f445 = (unsigned char)fileNo;
    if (color != 0) {
        color = (unsigned char)fileNo;
        kind = (unsigned char)character;
        fn_1_379C(self->f1b0, kind, color);
        self->f446 = kind;
        self->f447 = color;
    }
}
}
