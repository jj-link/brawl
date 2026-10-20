#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" {
ftEntry* getEntity__14ftEntryManagerFUl(u32);
void fn_27_116C2C(ftEntry*);
}

extern "C" void fn_27_10D0B0(void* self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_116C2C(entry);
}
