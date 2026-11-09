#include <types.h>
#include <ft/ft_entry_manager.h>
#pragma force_active on

extern "C" {
void fn_27_1246B4(void*, signed char);
void fn_27_111388(u8**, u32);
void fn_27_12AE90(void*, u32);

void fn_27_10A274(void* self, u32 entryId, s8 value) {
    ftEntryManager* manager = *(ftEntryManager**)((char*)self + 0x154);
    ftEntry* entry = manager->getEntity(entryId);

    fn_27_1246B4(entry->m_input, value);
    fn_27_111388((u8**)entry->m_owner, value == 1);

    for (int i = 0; i < entry->m_entryCount; ++i) {
        if (entry->m_instances[i].m_fighter != 0)
            fn_27_12AE90(entry->m_instances[i].m_fighter, value == 0);
    }
}
}