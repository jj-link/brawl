#include <string.h>
#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_80052DB0();
void* fn_80158BE0();
void fn_8015A138(void*, s32, s32);
extern void* g_GameGlobal;
extern struct Table lbl_1_rodata_A20;
}

struct Table { u8 values[5]; };

struct Bits {
    u8 a : 1; u8 b : 1; u8 c : 1; u8 d : 1;
    u8 e : 1; u8 f : 1; u8 g : 1; u8 h : 1;
};

typedef struct {
    u8 a : 6;
    u8 b : 2;
} Flags8;

typedef struct {
    u8 a : 3;
    u8 b : 3;
    u8 c : 2;
} Flags9;

extern "C" void fn_1_260A0(void* arg0v) {
    u8* arg0 = (u8*)arg0v;
    u8* r31;
    u8* r30;
    u8* gg18;
    s32 n;
    s32 v;
    void* ret;
    const u8* tp;

    r30 = *(u8**)((u8*)g_GameGlobal + 0x30);
    r31 = *(u8**)((u8*)g_GameGlobal + 0x8);
    memset(r30 + 0x4910, 0, 0x48);
    n = fn_80052DB0();
    if (*(u8**)((u8*)g_GameGlobal + 0x30) != 0) {
        (*(u8**)((u8*)g_GameGlobal + 0x30))[0x4928] = 0;
        *(s32*)(*(u8**)((u8*)g_GameGlobal + 0x30) + 0x492C) = n;
    }
    if (*(u8**)((u8*)g_GameGlobal + 0x30) != 0) {
        (*(u8**)((u8*)g_GameGlobal + 0x30))[0x4930] = 0;
        *(s32*)(*(u8**)((u8*)g_GameGlobal + 0x30) + 0x4934) = -1;
    }
    ((Flags8*)(r31 + 8))->a = 6;
    ((Flags9*)(r31 + 9))->b = 1;
    r31[0x14] = 0;
    *(u32*)(r31 + 0x20) = 0x4650;
    gg18 = *(u8**)((u8*)g_GameGlobal + 0x18);
    r31[0x98] = gg18[0x24];
    *(u16*)(r30 + 0x5F8) = 0x3D;
    *(u32*)(r30 + 0x61C) = 0x4650;
    r30[0x604] = 2;
    r30[0x603] = 0;
    *(u32*)(r30 + 0x620) = 0x5A000100;
    *(u32*)(r30 + 0x624) = 0x5A000100;
    *(u32*)(r30 + 0x62C) = 0;
    *(u32*)(r30 + 0x628) = 0;
    r30[0x2B9] = r31[0x98];
    r30[0x2B5] = 1;
    r30[0x2B4] = 1;
    r30[0x5FA] = (u8)(arg0[0x31] - 1);
    *(s8*)(r30 + 0x2B6) = -1;
    *(s8*)(r30 + 0x2B7) = -1;
    *(s8*)(r30 + 0x2B8) = -1;
    Bits* flags606 = (Bits*)(r30 + 0x606);
    flags606->b = 0;
    ((Bits*)(r30 + 0x607))->c = 1;
    r30[0x606] |= 0x20;
    ((Bits*)(r30 + 0x607))->d = 1;
    flags606->a = 0;
    ((Bits*)(r30 + 0x4924))->a = 0;
    ((Bits*)(r30 + 0x4924))->b = 1;
    ((Bits*)(r30 + 0x4924))->f = 0;
    r30[0x4916] = 0;
    Table sp = lbl_1_rodata_A20;
    v = sp.values[arg0[0x32]];
    v -= 1;
    v -= *(s32*)(arg0 + 0x24);
    if (v < 0) {
        v = 0;
    }
    if (v > 0xE) {
        v = 0xE;
    }
    r30[0x5FD] = (u8)v;
    r31[0x9C] = arg0[0x31];
    *(u16*)(r31 + 0xBA) = 0;
    arg0[0x2E] = 0;
    if (arg0[0x32] >= 2 && *(s32*)(arg0 + 0x28) == 0 && *(u32*)(arg0 + 0x1C) <= 0x7E90) {
        arg0[0x2E] = 1;
    }
    r31[0xF4] = 0x3C;
    r31[0xF5] = 3;
    r31[0xF8] = 1;
    ((Flags9*)(r31 + 9))->b = ((Flags9*)(r31 + 9))->b + 1;
    if (arg0[0x2E] != 0) {
        r31[0x150] = 0x3D;
        ((Flags9*)(r31 + 9))->b = ((Flags9*)(r31 + 9))->b + 1;
    } else {
        r31[0x150] = 0x3E;
    }
    r31[0x151] = 3;
    r31[0x154] = 1;
    r31[0x1AC] = 0x3E;
    r31[0x1AD] = 3;
    r31[0xA0] = 0;
    r31[0xFC] = 1;
    r31[0x158] = 2;
    r31[0x1B4] = 3;
    ret = fn_80158BE0();
    fn_8015A138(ret, arg0[0x2E], arg0[0x32]);
}
