#include <types.h>
#pragma force_active on

extern "C" {
extern s32 fn_8005680C(void);
extern char* g_GameGlobal;

s32 fn_80052B24(void) {
    s32 idx = fn_8005680C();
    u16 v = *(u16*)(*(char**)((char*)g_GameGlobal + 0x24) + (idx << 1) + 0xD58);
    return (v >> 15) & 1;
}
}
