#include <ft/ft_manager.h>
#include <ft/ft_slot.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(ftEntryManager*, u32);

extern "C" s32 getSlotNo__9ftManagerFl(ftManager* __restrict self, s32 entryId) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(self->m_entryManager, entryId);
    ftSlot* slots = g_ftSlotManager->m_slots;
    return slots[entry->m_slotIndex].m_slotNo;
}
