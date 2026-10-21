#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern "C" int fn_8005680C(void);
extern void* g_GameGlobal;

extern "C" s32 fn_80052B94(void) {
    int idx = fn_8005680C();
    char* base = *(char**)((char*)g_GameGlobal + 0x24);
    u16 v = *(u16*)(base + idx * 2 + 0xD58);
    return (v >> 12) & 1;
}
