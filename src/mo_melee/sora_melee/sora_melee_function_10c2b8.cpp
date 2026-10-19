#pragma force_active on
class ftEntryManager;
class ftManager;

class ftEntryManager {
public:
    void* getEntity(unsigned long id);
};

class ftManager {
public:
    void addDragoon(int idx, unsigned long id);
};

extern "C" void* fn_27_1161D4(void* entity, unsigned long id, int flag);

void ftManager::addDragoon(int idx, unsigned long id) {
    ftEntryManager* mgr = *(ftEntryManager**)((char*)this + 0x154);
    void* entity = mgr->getEntity(idx);
    fn_27_1161D4(entity, id, 1);
}
