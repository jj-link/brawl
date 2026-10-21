#pragma force_active on
typedef signed int s32;
typedef unsigned short u16;

extern "C" {
s32 fn_80056780(void);
extern void* g_GameGlobal;

s32 fn_80052810(void) {
    s32 idx = fn_80056780();
    char* base = *(char**)((char*)g_GameGlobal + 0x24);
    u16 v = *(u16*)(base + (idx * 2) + 0x842);
    return (v >> 13) & 1;
}
}
