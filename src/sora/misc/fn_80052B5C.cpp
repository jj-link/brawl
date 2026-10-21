#pragma force_active on
typedef unsigned short u16;
typedef int s32;

extern "C" {
extern s32 fn_8005680C(void);
extern void* g_GameGlobal;

s32 fn_80052B5C(void) {
    s32 idx = fn_8005680C();
    char* base = *(char**)((char*)g_GameGlobal + 0x24);
    u16 v = *(u16*)(base + (idx << 1) + 0xD58);
    return (v >> 0xD) & 1;
}
}
