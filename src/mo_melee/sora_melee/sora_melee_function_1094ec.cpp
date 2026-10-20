#include <ft/ft_slot_manager.h>
#include <ft/ft_slot.h>
#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_120A10(ftSlot* slot);

extern "C" bool fn_27_1094EC(s32 arg0, u32 index) {
    bool result = false;
    ftSlot* slot = g_ftSlotManager->m_slots + index;
    if (slot->_0x15c == 0) {
        if (fn_27_120A10(slot) == 1)
            result = true;
    }
    return result;
}
