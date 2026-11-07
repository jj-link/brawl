#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" u32* fn_8004E5A0(void* arg0);
extern s32 g_GameGlobal;

extern "C" s32 fn_8004F3BC(s32 arg0) {
    u32* bits = fn_8004E5A0((void*)g_GameGlobal);
    return (bits[arg0 / 32] & (1 << (arg0 % 32))) != 0;
}
