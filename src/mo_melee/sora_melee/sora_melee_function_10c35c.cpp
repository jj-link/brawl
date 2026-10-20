#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" int fn_27_116960(ftEntry* entry, unsigned int arg);

extern "C" void fn_27_10C35C(void* self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    fn_27_116960(entry, 1);
}
