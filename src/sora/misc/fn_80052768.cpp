#pragma force_active on
typedef unsigned short u16;
typedef int s32;

extern "C" {
extern s32 fn_80056780(void);
extern void* g_GameGlobal;

s32 fn_80052768(void) {
    s32 idx = fn_80056780();
    char* base = *(char**)((char*)g_GameGlobal + 0x24);
    return *(u16*)(base + idx * 2 + 0x842) & 0x3FF;
}
}
