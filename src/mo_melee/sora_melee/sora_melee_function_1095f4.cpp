#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u8* m_slots;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" void fn_27_11D32C(void*, u32, u32, u32);

extern "C" void fn_27_1095F4(void* p, u32 index, u32 arg) {
    fn_27_11D32C(g_ftSlotManager->m_slots + index * 0x4d4, arg, 0x2000, 0);
}
