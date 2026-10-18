#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u8* m_slots;
    s32 m_slotCount;
};

extern ftSlotManager* g_ftSlotManager;

extern "C" void fn_27_11F274(void* slot, u8 arg1, u32 arg2, u32 arg3);

extern "C" void fn_27_109660() {
    s32 count = g_ftSlotManager->m_slotCount;
    for (s32 i = 0; i < count; i++) {
        fn_27_11F274(g_ftSlotManager->m_slots + i * 0x4d4, 0xFF, 0x7000, 0);
    }
}
