#include <types.h>
#pragma force_active on

class ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_113D94(ftEntry*, float, u32, float, u32);

extern "C" void fn_27_10B59C(void* self, u32, u32 a, float f1, float f2, u32 c) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_113D94(entry, f1, a, f2, c);
}
