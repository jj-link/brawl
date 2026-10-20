#pragma force_active on
typedef unsigned int u32;
typedef int s32;
struct ftEntry;
struct ftEntryManager;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_115AC8(void*, void*);

extern "C" void fn_27_10D8F8(char* self, u32 unused, void* arg) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154));
    fn_27_115AC8(entry, arg);
    *(s32*)(self + 0x74) = -1;
    *(s32*)(self + 0x70) = -1;
}
