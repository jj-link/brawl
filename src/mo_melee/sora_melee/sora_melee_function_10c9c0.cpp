#pragma force_active on
typedef unsigned int u32;

struct ftEntry {
    unsigned char padding[0x18];
    u32 slotIndex;
};

struct ftSlot {
    unsigned char padding[0x4CC];
    u32 value;
    u32 trailing;
};

struct ftSlotManager {
    ftSlot* slots;
};

struct Fighter {
    unsigned char padding[0x154];
    u32 entryId;
};

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" ftSlotManager* g_ftSlotManager;

extern "C" u32 fn_27_10C9C0(Fighter self) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(self.entryId);
    return g_ftSlotManager->slots[entry->slotIndex].value;
}
