#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" u8 fn_8004EAD4(void* a);
extern s32 g_GameGlobal;

extern "C" s32 fn_800305B0(s32 arg0) {
    u32 mask = 1 << arg0;
    u8 v = fn_8004EAD4((void*)g_GameGlobal);
    return (v & mask) != 0;
}
