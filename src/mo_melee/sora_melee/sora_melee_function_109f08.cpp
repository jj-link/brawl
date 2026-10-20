#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_115928(ftEntry*);

extern "C" void fn_27_109F08(void* self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_115928(entry);
}
