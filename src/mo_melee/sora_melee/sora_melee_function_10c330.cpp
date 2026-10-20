#include <ft/ft_entry_manager.h>
#include <types.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_11676C(ftEntry*, u32);

extern "C" void fn_27_10C330(ftEntryManager* self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_11676C(entry, 1);
}
