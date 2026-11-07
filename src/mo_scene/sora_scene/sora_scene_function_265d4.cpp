#include <types.h>
#pragma force_active on

struct A { int a[5]; };
struct S { char pad[0x32]; unsigned char m; };
struct G {
    char pad[0x9c];
    unsigned short hi : 5;
    unsigned short lvl : 3;
    unsigned short lo : 8;
    char pad2[2];
    unsigned int fa0;
};

extern "C" {
u8 exchangeGmCharacterKindToMuCharKind__6muMenuFiii(s32 self, s32 a, s32 b, s32 c);
void* fn_8004E5D8(void*, s32);
void fn_80052AC0(s32, s32);
s32 fn_80055398(s32);
void fn_800553B8(s32);
extern void* g_GameGlobal;
extern A lbl_1_rodata_A38;
}

extern "C" void fn_1_265D4(S* arg0, s32 arg1, s32 arg2, u32 arg3) {
    G* g = (G*)fn_8004E5D8(g_GameGlobal, exchangeGmCharacterKindToMuCharKind__6muMenuFiii(arg1, arg1, arg2, arg3));
    if (g->fa0 < arg3) {
        g->fa0 = arg3;
    }
    if (arg2 != 0) {
        s32 lvl = arg0->m + 1;
        if ((s32)g->lvl < lvl) {
            g->lvl = lvl;
        }
        if (fn_80055398(0x29) == 1U && arg0->m == 0) {
            fn_80052AC0(0x78, 1);
        }
        A arr = lbl_1_rodata_A38;
        for (int i = 0; i < 5; i++) {
            int v = arr.a[i];
            if (fn_80055398(v) == 0) {
                int r = 0;
                switch (v) {
                case 0x29: if (arg0->m == 0) r = 1; break;
                case 0x2D: if (arg0->m == 1) r = 1; break;
                case 0x25: if (arg0->m == 2) r = 1; break;
                case 0x3E: if (arg0->m == 3) r = 1; break;
                case 0x07: if (arg0->m == 4) r = 1; break;
                }
                if (r != 0) fn_800553B8(v);
            }
        }
    }
}
