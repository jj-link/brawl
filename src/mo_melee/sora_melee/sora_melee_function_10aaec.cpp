#pragma force_active on

typedef unsigned long u32;

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" int fn_27_114210(ftEntry*);

extern "C" int fn_27_10AAEC(const u32* self)
{
    u32 id = self[0x55];
    ftEntry* entry = getEntity__14ftEntryManagerFUl(id);
    return fn_27_114210(entry);
}
