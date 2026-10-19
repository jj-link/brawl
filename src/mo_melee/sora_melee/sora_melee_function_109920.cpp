#include <ft/ft_entry_manager.h>
#include <types.h>
#pragma force_active on

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);

extern "C" void fn_27_1139A8();

extern "C" void fn_27_109920(ftEntryManager* self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_1139A8();
    *(u8*)((char*)entry + 0x0C) = 0;
}
