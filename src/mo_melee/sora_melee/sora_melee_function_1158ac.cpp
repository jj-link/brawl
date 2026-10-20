#include <types.h>
#include <ft/ft_slot_manager.h>
#pragma force_active on

extern "C" void fn_27_11F274(void* slot, u8 arg1, u32 arg2, u32 arg3);

struct SlotRefData {
    u8 pad0[0x8];
    u8 m_count;
    u8 pad1[0xF];
    u32 m_slotIndex;
};

extern "C" void fn_27_1158AC(SlotRefData* data) {
    for (u8 i = 0; i < data->m_count; i++) {
        fn_27_11F274((u8*)g_ftSlotManager->m_slots + data->m_slotIndex * 0x4D4, i, 0x4000, 0);
    }
}
