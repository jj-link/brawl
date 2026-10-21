#pragma force_active on
struct ftEntry { unsigned char padding[0x50]; int heartSwap; };
struct ftEntryManager;
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(ftEntryManager*, unsigned long);
struct ftManager { unsigned char padding[0x154]; ftEntryManager* entryManager; };
extern "C" bool isProcessHeartSwap__9ftManagerFi(ftManager* __restrict self, int id) {
    return getEntity__14ftEntryManagerFUl(self->entryManager, id)->heartSwap != -1;
}
