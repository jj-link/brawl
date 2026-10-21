#pragma force_active on

struct ftEntryManager;

struct ftEntry {
    char pad[0x50];
    int opposite;
};

struct soDamageAttackerInfo {
    char pad[0x20];
    int entryId;
};

class ftManager {
public:
    void toKnockOutHeartSwapOpposite(int, soDamageAttackerInfo*);

private:
    char pad[0x154];
    ftEntryManager* m_entryMgr;
};

extern "C" {
    ftEntry* getEntity__14ftEntryManagerFUl(ftEntryManager*, unsigned int);
    void fn_27_11A418(ftEntryManager*, int);
    unsigned int fn_27_1190D0(ftEntryManager*, unsigned int);
    void fn_27_1169D8(ftEntry*, soDamageAttackerInfo*);
}

void ftManager::toKnockOutHeartSwapOpposite(int entryId, soDamageAttackerInfo* info) {
    int opposite = getEntity__14ftEntryManagerFUl(m_entryMgr, entryId)->opposite;

    fn_27_11A418(m_entryMgr, 0);

    if (fn_27_1190D0(m_entryMgr, opposite) == 1U) {
        ftEntry* entry = getEntity__14ftEntryManagerFUl(m_entryMgr, opposite);
        if (opposite == info->entryId) {
            info->entryId = entryId;
        }
        fn_27_1169D8(entry, info);
    }
}
