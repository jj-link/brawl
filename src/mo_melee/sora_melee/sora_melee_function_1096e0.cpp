#include <types.h>
#include <ft/ft_slot_manager.h>
#pragma force_active on

extern "C" void fn_27_11D0FC(void* slot);

extern "C" void fn_27_1096E0() {
    u32 count = g_ftSlotManager->m_slotCount;
    for (s32 i = 0; i < (s32)count; i++) {
        u8* base = (u8*)g_ftSlotManager->m_slots;
        fn_27_11D0FC(base + i * 0x4d4);
    }
}
