#include <types.h>
#pragma force_active on

extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_11FADC(void* self, u32 arg);
extern "C" void* g_ftSlotManager;

struct ftEntryLocal {
    u8 pad[0x18];
    s32 slot;
};

extern "C" void fn_27_10D5E4(void* self, u32 unused, u32 arg) {
    ftEntryLocal* entry = (ftEntryLocal*)getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    char* base = *(char**)g_ftSlotManager;
    fn_27_11FADC(base + entry->slot * 0x4d4, arg);
}
