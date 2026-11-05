#include <types.h>
#pragma force_active on
extern "C" s32 fn_8005680C(void);
extern void* g_GameGlobal;
extern "C" void fn_80052AC0(void* unused, s32 amount) {
    s32 idx = fn_8005680C();
    u8* base = *(u8**)((u8*)g_GameGlobal + 0x24) + 0xD58;
    u16 v = ((u16*)base)[idx];
    amount += v & 0x3FF;
    if (amount >= 1000) {
        amount = 999;
    }
    *(u16*)(base + idx * 2) = (v & 0xF000) | 0x8000 | amount;
}
