#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_11FBA4(void* p, u32 arg);
extern "C" void* g_ftSlotManager;

extern "C" void fn_27_10D634(void* self, u32 unused, u32 arg) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    u32 idx = *(u32*)((char*)entry + 0x18);
    char* base = *(char**)g_ftSlotManager;
    fn_27_11FBA4(base + idx * 0x4d4, arg);
}
