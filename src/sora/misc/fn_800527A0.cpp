#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern "C" s32 fn_80056780(u16);
extern void* g_GameGlobal;

s32 gmCheckExistFigure(u16 arg0) {
    s32 idx = fn_80056780(arg0);
    u8* base = *(u8**)((u8*)g_GameGlobal + 0x24);
    u16 v = *(u16*)(base + idx * 2 + 0x842);
    return (v >> 15) & 1;
}
