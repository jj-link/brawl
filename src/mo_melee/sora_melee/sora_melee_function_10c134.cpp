#include <types.h>
#pragma force_active on

class ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_115DF0(ftEntry*, u32, u32, float);

extern "C" void fn_27_10C134(void* self, u32 unused, u32 a, u32 b, float f) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_115DF0(entry, a, b, f);
}
