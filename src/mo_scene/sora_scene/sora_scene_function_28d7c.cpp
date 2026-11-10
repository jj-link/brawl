#include <types.h>
#pragma force_active on

struct S {
    char pad[0x18];
    s32 a;   // 0x18
    s32 b;   // 0x1C
    char pad2[4];
    s32 c;   // 0x24
};

struct G {
    char pad[0x9C];
    u16 pre : 8;
    u16 lvl : 3;
    u16 post : 5;
    char pad2[6];
    u32 fa4;   // 0xA4
};

struct R {
    char pad[0x34D4];
    u16 hi : 5;
    u16 lvl : 3;
    u16 lo : 8;
};

struct A { s32 a[6]; };

extern "C" {
int exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int self);
void* fn_8004E5D8(void*, u8);
int fn_8004F258(u32*, u32, s32);
void fn_80052AC0(s32, s32);
u32 fn_80055398(s32);
void fn_800553B8(s32);
extern void* g_GameGlobal;
extern A lbl_1_rodata_C10;
}

extern "C" void fn_1_28D7C(S* arg0, s32 arg1) {
    void* r28 = *(void**)((char*)g_GameGlobal + 0x8);
    void* r27 = *(void**)((char*)g_GameGlobal + 0x18);
    u32 sp8;
    if (arg0->a == 1) {
        u32 v = *(u32*)((char*)r27 + 0x260);
        G* g = (G*)fn_8004E5D8(g_GameGlobal, exchangeGmCharacterKindToMuCharKind__6muMenuFiii(*(u8*)((char*)r28 + 0x98)));
        if (g->fa4 < v) {
            g->fa4 = v;
        }
        if (arg1 != 0) {
            s32 lvl = arg0->b + 1;
            if ((s32)g->lvl < lvl) {
                g->lvl = lvl;
            }
        }
    } else {
        u8 t26 = exchangeGmCharacterKindToMuCharKind__6muMenuFiii(*(u8*)((char*)r28 + 0x98));
        u8 t25 = exchangeGmCharacterKindToMuCharKind__6muMenuFiii(*(u8*)((char*)r28 + 0xF4));
        sp8 = 0;
        fn_8004F258(&sp8, *(u32*)((char*)r27 + 0x260), -1);
        fn_8004F258(&sp8, *(u32*)((char*)r27 + 0x50C), -1);
        void* rec = *(void**)((char*)g_GameGlobal + 0x24);
        if (*(u32*)((char*)rec + 0x34D8) < sp8) {
            *(u16*)((char*)rec + 0x34D4) = (u16)(*(u16*)((char*)rec + 0x34D4) | 2);
            *(u32*)((char*)rec + 0x34D8) = sp8;
            *(u8*)((char*)rec + 0x3524) = t26;
            *(u8*)((char*)rec + 0x3525) = *(u8*)((char*)r28 + 0x9E);
            *(u8*)((char*)rec + 0x3526) = t25;
            *(u8*)((char*)rec + 0x3527) = *(u8*)((char*)r28 + 0xFA);
        }
        if (arg1 != 0) {
            s32 lvl = arg0->b + 1;
            R* rr = (R*)rec;
            if ((s32)rr->lvl < lvl) {
                rr->lvl = lvl;
            }
        }
    }
    if (arg1 != 0) {
        if (fn_80055398(0x41) == 1 && arg0->b == 1) {
            fn_80052AC0(0x28E, 1);
        }
        A arr = lbl_1_rodata_C10;
        s32 i;
        s32 v;
        s32* p = arr.a;
        for (i = 0; i < 6; i++, p++) {
            v = *p;
            if (fn_80055398(v) == 0) {
                s32 r = 0;
                switch (v) {
                case 0x2C: if (arg0->c == 0) r = 1; break;
                case 0x22: if (arg0->b == 0) r = 1; break;
                case 0x41: if (arg0->b == 1) r = 1; break;
                case 0x5F: if (arg0->b == 2) r = 1; break;
                case 0x3C: if (arg0->b == 3) r = 1; break;
                case 0x62: if (arg0->b == 4) r = 1; break;
                }
                if (r != 0) fn_800553B8(v);
            }
        }
    }
}
