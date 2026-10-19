#include <types.h>
#pragma force_active on

class ftEntry;
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116A78(ftEntry*, u32, u32);

extern "C" void fn_27_10CFEC(void* self, u32 unused, u32 a, u32 b) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_116A78(entry, a, b);
}
