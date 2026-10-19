#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(void* mgr, u32 id);
extern "C" void fn_27_1169FC(ftEntry* entry, u32 arg);

extern "C" void fn_27_10C280(void* self, u32 id, u32 arg) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), id);
    fn_27_1169FC(entry, arg);
}
