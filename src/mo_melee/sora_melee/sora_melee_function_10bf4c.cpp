#pragma force_active on
struct ftEntry {
    char pad0[0x28];
    void* data;
    char pad2C[0x24];
    int parent;
};

struct ftEntryManager;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(ftEntryManager*, unsigned long);
extern "C" void fn_27_112C10(void*, int);
extern "C" int fn_27_112C70(void*);
extern "C" void fn_27_112C58(void*, int);

struct ftManager {
    char pad0[0x154];
    ftEntryManager* entries;
};

extern "C" void pickupCoin__9ftManagerFii(ftManager* self, int entryId, int amount) {
    int parent = getEntity__14ftEntryManagerFUl(self->entries, entryId)->parent;
    ftEntryManager* entries = self->entries;
    if (parent != -1) {
        entryId = parent;
    }
    void* data = getEntity__14ftEntryManagerFUl(entries, entryId)->data;
    fn_27_112C10(data, amount);
    fn_27_112C58(data, amount + fn_27_112C70(data));
}
