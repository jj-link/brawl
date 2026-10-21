#include <types.h>
#pragma force_active on

extern "C" int fn_8005680C(void);
extern void* g_GameGlobal;

extern "C" void fn_80052CCC(void* unused, u32 flag) {
    s32 idx = fn_8005680C();
    u8* base = *(u8**)((u8*)g_GameGlobal + 0x24) + 0xD58;
    u16 v = ((u16*)base)[idx];
    u16 r;

    if (flag == 1) {
        r = v | 0x1000;
    } else {
        r = v & ~0x1000;
    }

    *(u16*)(base + idx * 2) = r;
}
