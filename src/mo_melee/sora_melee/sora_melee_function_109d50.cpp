#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_114308(ftEntry* entry, u8 value);

extern "C" void fn_27_109D50(void* self, u32 unused, u32 value) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_114308(entry, (u8)value);
}
