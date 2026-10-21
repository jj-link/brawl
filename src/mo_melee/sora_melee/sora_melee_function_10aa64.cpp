#pragma force_active on
struct Fighter {
    unsigned char padding[0x154];
    unsigned int entryId;
};

struct ftEntry {
    unsigned char padding[0xA];
    unsigned char value;
};

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(unsigned int);

extern "C" unsigned char fn_27_10AA64(Fighter* __restrict self)
{
    return getEntity__14ftEntryManagerFUl(self->entryId)->value;
}
