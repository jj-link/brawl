#include <ft/ft_entry_manager.h>
#include <types.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);

extern "C" void fn_27_113C0C(ftEntry* entry, float f, u32 a, u32 b, u32 c);

extern "C" void fn_27_10B534(ftEntryManager* self, u32 unused, u32 a, u32 b, u32 c, float f) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_113C0C(entry, f, a, b, c);
}
