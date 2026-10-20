#include <ft/ft_manager.h>
#include <types.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116D48(ftEntry* entry, Vec3f* pos, float lr, u32 flags);

void ftManager::setWarpFighter(int entryId, Vec3f* pos, float lr, u32 flags) {
    ftEntry* entry = m_entryManager->getEntity(entryId);
    fn_27_116D48(entry, pos, lr, flags);
}
