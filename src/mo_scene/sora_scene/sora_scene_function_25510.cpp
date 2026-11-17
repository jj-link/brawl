#include <types.h>
#include <mu/menu.h>

#pragma force_active on

extern "C" {
extern u8* g_GameGlobal;

void fn_8005033C(void*);
void fn_1_26A08(u8);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
s8 getFighterColorFileNo__6muMenuFiii(int, int);
}

struct Flags {
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 1;
};

struct Bits {
    u8 hi : 3;
    u8 low : 5;
};

extern "C" void fn_1_25510(u8* self) {
    s8 result = 0;
    u8* p8 = *(u8**)(g_GameGlobal + 8);
    u8* p30 = *(u8**)(g_GameGlobal + 0x10);
    u8* p18 = *(u8**)(g_GameGlobal + 0x18);
    u8* s = self;

    s[0x32] = (p30[0x2e] >> 5) & 7;
    s[0x31] = (p30[0x2e] >> 2) & 7;
    *(int*)(s + 0x14) = 0;
    *(int*)(s + 0x18) = 0;
    *(int*)(s + 0x1c) = 0;
    *(int*)(s + 0x24) = 0;
    *(int*)(s + 0x28) = 0;
    s[0x2c] = 1;
    s[0x2d] = 1;

    fn_8005033C(p8);
    ((Bits*)(p8 + 9))->hi = 1;
    p8[0x13] = 0;
    *(int*)(p8 + 0x20) = 0x4650;
    ((Bits*)(p8 + 0xe))->hi = s[0x32];
    p8[0xc] |= 0x80;
    p8[0xb] &= ~4;
    *(short*)(p8 + 0x80) = 0x2d;
    *(short*)(p8 + 0x82) = 0x5a;
    p8[0x99] = 0;
    p8[0x98] = p30[0xb8];
    p8[0xa3] = 0;

    u8 color = p30[0xbd];
    p8[0x9e] = color;
    int c = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(p8[0x98]);
    if (c == 0x28) {
        result = 0;
    } else {
        result = getFighterColorFileNo__6muMenuFiii(c, color);
    }
    p8[0x9d] = result;

    p8[0xb0] = p30[0xd0];
    p8[0x9f] = p30[0xbf];
    p8[0x9a] = 0;
    *(int*)(p18 + 0x258) = 0;
    *(int*)(p18 + 0x260) = 0;
    *(int*)(p18 + 0x25c) = 0;
    *(int*)(p18 + 0x1368) = 0;
    p18[0x136c] = 0;
    *(int*)(p18 + 0x1370) = 0;

    u8 character = p8[0x98];
    s[0x33] = character;
    fn_1_26A08(character);

    u8* p = *(u8**)(g_GameGlobal + 0x30);
    ((Flags*)(p + 0x4924))->b = 0;
}
