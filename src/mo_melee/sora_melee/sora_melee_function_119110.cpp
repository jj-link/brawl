#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

class ftEntry;

class ftEntryManager {
public:
    ftEntry* getEntity(u32 idx);

private:
    char* m_entries;
};

ftEntry* ftEntryManager::getEntity(u32 idx) {
    return (ftEntry*)(m_entries + (u8)idx * 0x244);
}
