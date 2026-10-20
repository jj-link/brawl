#pragma force_active on
typedef unsigned int u32;

struct ftEntry {
    char padding[0x5C];
    u32 value;
};

struct Fighter {
    char padding[0x154];
    u32 entryId;
};

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);

extern "C" u32 fn_27_10AAC4(Fighter* __restrict self)
{
    return getEntity__14ftEntryManagerFUl(self->entryId)->value;
}
