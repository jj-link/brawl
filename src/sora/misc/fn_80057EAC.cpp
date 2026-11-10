#include <types.h>
#pragma force_active on

extern "C" {
u8 fn_800515C0(void);
u8 fn_80051658(void);
u32 fn_80052A0C(u32);
void* fn_8004E5D8(void*, int);
void fn_8005161C(u32);
void fn_800516B4(u32);
u32 fn_80050738(void);
u32* fn_8004E580(void*);
u32 fn_8005297C(void);
extern void* g_GameGlobal;
}

extern "C" void fn_80057EAC(void) {
    if (!(fn_800515C0() & 4)) {
        int i;
        u32 f = 0;
        if (fn_80052A0C(1) == 1) f = 1;
        if (fn_80052A0C(3) == 1) f = 1;
        for (i = 0; i < 0x23; i++) {
            if ((*(u16*)((char*)fn_8004E5D8(g_GameGlobal, i) + 0x9c) >> 8) & 7) {
                f = 1;
                break;
            }
        }
        if (*(u32*)(*(char**)((char*)g_GameGlobal + 0x24) + 0x804) >> 31) f = 1;
        if (f == 1) fn_8005161C(4);
    }
    if (!(fn_800515C0() & 8)) {
        u32 f = 0;
        if (fn_80052A0C(2) == 1) f = 1;
        if (fn_80052A0C(4) == 1) f = 1;
        if (fn_80050738() >= 200) f = 1;
        if (f == 1) fn_8005161C(8);
    }
    if (!(fn_800515C0() & 0x10)) {
        int id;
        u32 g = 0;
        int n;
        int k;
        if (fn_80052A0C(3) == 1) g = 1;
        n = 0;
        for (k = 0, id = 1; k < 14; id += 3, n++, k++) {
            u32* bits = fn_8004E580(g_GameGlobal);
            if (!((1 << (id % 32)) & bits[id / 32])) break;
        }
        if (n >= 14) g = 1;
        if (g == 1) fn_8005161C(0x10);
    }
    if (!(fn_800515C0() & 0x20)) {
        u32 h = 0;
        if (fn_8005297C() >= 350) h = 1;
        if (h == 1) fn_8005161C(0x20);
    }
    if (!(fn_80051658() & 8) && fn_80050738() >= 200) {
        fn_800516B4(8);
    }
}
