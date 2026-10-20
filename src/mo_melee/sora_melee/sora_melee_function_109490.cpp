#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u8* m_slots;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" u32 fn_27_120818(void*);

extern "C" u32 fn_27_109490(void* p, u32 index) {
    u8* slot = g_ftSlotManager->m_slots + index * 0x4d4;
    u32 result = 0;
    if (*(slot + 0x15c) == 0) {
        if (fn_27_120818(slot) == 1) {
            result = 1;
        }
    }
    return result;
}
