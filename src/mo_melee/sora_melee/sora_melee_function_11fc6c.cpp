#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" s32 fn_27_1448C0(s32, s32, s32, s32, s32, u8, u8);
extern int lbl_27_bss_31F8;

extern "C" s32 fn_27_11FC6C(char* self, s32 a1, s32 a2) {
    u8 k;
    for (k = 0; k < 8; ++k) {
        char* slot = self + k * 0x30;
        s32 slotOwner = *(s32*)(slot + 0x338);
        if (slotOwner == -1) continue;
        if (a1 != *(s32*)(slot + 0x330)) continue;
        if (a2 != -1 && a2 != slotOwner) continue;
        u8 flag = *(u8*)(self + 0x15E);
        if (((u32)(-((((char*)g_ftManager)[0x6C] >> 6) & 1) | ((((char*)g_ftManager)[0x6C] >> 6) & 1)) >> 31) == 1 && ((((char*)g_ftManager)[0x6E] >> 2) & 1) == 0) flag = 0;
        if (fn_27_1448C0(lbl_27_bss_31F8, *(s32*)(slot + 0x330), *(s32*)(self + 0x174), slotOwner, *(s32*)(slot + 0x334), *(u8*)(self + 0x15B), flag) == 0) return 0;
    }
    return 1;
}
