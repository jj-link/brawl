#pragma force_active on
struct Fighter {
    unsigned char pad[0x50];
    int entryId;
    unsigned char pad3[0x4];
    void* field58;
};

struct EntryManager {
    void* entries;
};

extern "C" EntryManager* g_ftEntryManager;
extern "C" int fn_27_111364(void*);

extern "C" int fn_27_116F60(Fighter* fighter, unsigned int arg4, unsigned int arg5) {
    if (arg5 == 1) {
        if (fighter->entryId != -1) {
            unsigned int index = (unsigned char)fighter->entryId;
            char* p = (char*)g_ftEntryManager->entries + index * 0x244;
            if (arg4 == 1) {
                return *(int*)(p + 0x58);
            }
            return fn_27_111364(*(void**)(p + 0x28));
        }
    }
    if (arg4 == 1) {
        return (int)fighter->field58;
    }
    return fn_27_111364(*((void**)fighter + 0x28 / 4));
}
