#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u8* m_slots;
    s32 m_slotCount;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" void fn_27_11F274(void* slot, u8 arg1, u32 arg2, u32 arg3);

extern "C" void fn_27_115AC8(void* self, u32 arg1) {
    if (arg1 == 1) {
        u32 index = *(u32*)((u8*)self + 0x18);
        fn_27_11F274(g_ftSlotManager->m_slots + index * 0x4D4, 0xFF, 0x1000, 0);
        *((u8*)self + 0x10) = 0;
    } else {
        *((u8*)self + 0x10) = 2;
    }
}
