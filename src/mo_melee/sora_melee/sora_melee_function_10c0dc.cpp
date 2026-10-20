#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_115B94(ftEntry*, u32, u32, u32);

extern "C" void fn_27_10C0DC(void* self, u32 unused, u32 a, u32 b, u32 c) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_115B94(entry, a, b, c);
}
