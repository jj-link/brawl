#pragma force_active on
class Fighter {
public:
    enum ScalingKind { ScalingKind_Unk = 0 };
    enum ScalingType { ScalingType_Unk = 0 };
};

class ftEntryManager;
class ftOwner;

class ftEntry {
public:
    char pad[0x28];
    ftOwner* m_owner;
};

class ftManager {
public:
    void setInfiniteScaling(int entryId, Fighter::ScalingKind kind, Fighter::ScalingType type);

private:
    char pad[0x154];
    ftEntryManager* m_entryMgr;
};

extern "C" {
    ftEntry* getEntity__14ftEntryManagerFUl(ftEntryManager* mgr, unsigned int id);
    void setInfiniteScaling__7ftOwnerFQ27Fighter11ScalingKindQ27Fighter11ScalingType(ftOwner* owner, unsigned int kind, unsigned int type);
    void fn_27_116A78(ftEntry* entry, unsigned int kind, unsigned int type);
}

void ftManager::setInfiniteScaling(int entryId, Fighter::ScalingKind kind, Fighter::ScalingType type) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(m_entryMgr, entryId);
    setInfiniteScaling__7ftOwnerFQ27Fighter11ScalingKindQ27Fighter11ScalingType(entry->m_owner, kind, type);

    ftEntry* entry2 = getEntity__14ftEntryManagerFUl(m_entryMgr, entryId);
    fn_27_116A78(entry2, kind, type);
}
