#include <ft/ft_slot_manager.h>
#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_1456B4(s32 unused, u32 idx) {
    return *(u32*)((u8*)g_ftSlotManager + (idx << 2) + 0x78);
}
}
