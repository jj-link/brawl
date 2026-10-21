#pragma force_active on
typedef unsigned long u32;
struct ftEntry;
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116FC4(ftEntry*, u32);
extern "C" void fn_27_10A0C4(const u32* self)
{
    u32 id = self[0x55];
    ftEntry* entry = getEntity__14ftEntryManagerFUl(id);
    fn_27_116FC4(entry, 1);
}
