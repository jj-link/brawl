#include <types.h>
#pragma force_active on
extern "C" u32* fn_8004E580(void*);
extern "C" u32* fn_8004E634(void*);
extern "C" u8* fn_8004E7B8(void*, int);
extern "C" u32 fn_8005297C();
extern void* g_GameGlobal;
extern "C" void fn_80056E68() {
    if (!(*fn_8004E580(g_GameGlobal) & 0x80000000) && *fn_8004E634(g_GameGlobal) / 60 / 60 >= 10) {
        *fn_8004E580(g_GameGlobal) |= 0x40000000;
    } else if (!(*fn_8004E580(g_GameGlobal) & 0x400000) && fn_8005297C() >= 250) {
        *fn_8004E580(g_GameGlobal) |= 0x200000;
    } else if (!(*fn_8004E580(g_GameGlobal) & 0x80000) && (int)*fn_8004E7B8(g_GameGlobal, 0x22) >= 15) {
        *fn_8004E580(g_GameGlobal) |= 0x40000;
    } else if (!(*fn_8004E580(g_GameGlobal) & 2)) {
        u8* p = *(u8**)((u8*)g_GameGlobal + 0x18);
        u32 total = 0;
        if (!p[0x25]) total = *(u32*)(p + 0x254);
        if (!p[0x2d1]) total += *(u32*)(p + 0x500);
        if (!p[0x57d]) total += *(u32*)(p + 0x7ac);
        if (!p[0x829]) total += *(u32*)(p + 0xa58);
        if (total >= 10) *fn_8004E580(g_GameGlobal) |= 1;
    }
}