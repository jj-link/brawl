#pragma force_active on

struct FighterEntry {
    int unused;
    int entryId;
};

class EntryArray {
public:
    virtual ~EntryArray();
    virtual FighterEntry*& at(int index);
};

struct EntryContainer {
    unsigned char padding[8];
    EntryArray entries;
};

struct ftManager {
    unsigned char padding[0x154];
    EntryContainer* container;
};

extern "C" int getEntryIdFromIndex__9ftManagerFi(
    ftManager* __restrict self, int index)
{
    return self->container->entries.at(index)->entryId;
}
