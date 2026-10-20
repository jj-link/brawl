#pragma force_active on
typedef unsigned int u32;

struct ftEntry {
    char padding[0x18];
    u32 slotIndex;
};

struct ftSlotManager {
    char* slots;
};

struct Fighter {
    char padding[0x154];
    u32 entryId;
};

extern "C" {
extern ftSlotManager* g_ftSlotManager;
ftEntry* getEntity__14ftEntryManagerFUl(u32);
int fn_27_11F9C8(char*);

int fn_27_10B2A4(const Fighter* __restrict self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(self->entryId);
    return fn_27_11F9C8(g_ftSlotManager->slots + entry->slotIndex * 0x4D4);
}
}
