#include <types.h>
#pragma force_active on

class ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116F2C(ftEntry* entry, u32 arg);

extern "C" void fn_27_10A0F0(void* self, u32 unused, u32 arg) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_116F2C(entry, arg);
}
