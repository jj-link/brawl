#include <types.h>
#pragma force_active on
extern "C" {
extern int lbl_1_bss_1A60;
struct Global { char pad[8]; char* dest; char pad2[4]; char* src; };
extern Global* g_GameGlobal;
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_8004D674(Global*, int, void*);
void fn_1_33B24() {
    char* s;
    char* d;
    char* data;
    int i = 0;
    d = g_GameGlobal->dest;
    s = g_GameGlobal->src;
    data = d + 0xa4;
    for (; i < lbl_1_bss_1A60; s += 0x5c, d += 0x5c, data += 0x5c, ++i) {
        if (*(u8*)(s + 0xb9) == 0) {
            u8 kind = *(u8*)(s + 0xb8);
            u8 costume = *(u8*)(s + 0xbd);
            int character = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
            int color = character == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(character, costume);
            *(u8*)(d + 0x99) = 0;
            *(u8*)(d + 0x98) = kind;
            *(u8*)(d + 0xa3) = 0;
            *(u8*)(d + 0x9d) = color;
            *(u8*)(d + 0x9e) = costume;
            u8 stage = *(u8*)(s + 0xd0);
            *(u8*)(d + 0xb0) = stage;
            if (stage != 0x78)
                fn_8004D674(g_GameGlobal, stage, data);
            else
                *(u16*)(d + 0xa4) = 0;
            *(u8*)(d + 0x9f) = *(u8*)(s + 0xbf);
            *(u8*)(d + 0x9a) = i;
        }
    }
}
}