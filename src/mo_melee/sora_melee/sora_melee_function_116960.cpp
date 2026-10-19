#pragma force_active on
struct Fighter {
    unsigned char pad[0x50];
    int entryId;
};

struct EntryManager {
    void* entries;
};

extern "C" EntryManager* g_ftEntryManager;
extern "C" int fn_27_111D70(void*);

extern "C" int fn_27_116960(Fighter* fighter, unsigned int arg) {
    if (arg == 1 && fighter->entryId != -1) {
        unsigned int index = (unsigned char)fighter->entryId;
        void* entries = g_ftEntryManager->entries;
        void* entry = static_cast<char*>(entries) + index * 0x244;
        return fn_27_111D70(*reinterpret_cast<void**>(static_cast<char*>(entry) + 0x28));
    }
    return fn_27_111D70(*reinterpret_cast<void**>(reinterpret_cast<char*>(fighter) + 0x28));
}
