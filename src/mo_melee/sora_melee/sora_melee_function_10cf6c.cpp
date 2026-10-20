#include <ft/ft_manager.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116C00(ftEntry*);

void ftManager::setCurry(int entryId) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)this + 0x154));
    fn_27_116C00(entry);
}
