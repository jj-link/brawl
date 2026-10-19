#pragma force_active on
class ftEntity {
public:
    unsigned char pad[0x2c];
    void* m_child;
};

class ftEntryManager {
public:
    ftEntity* getEntity(unsigned long id);
};

struct ftOwner {
    unsigned char pad[0x154];
    ftEntryManager* m_entryManager;
};

extern "C" {
void fn_27_124364(void* obj, unsigned long id);

void fn_27_10A128(ftOwner* owner, unsigned long entityId, unsigned long id) {
    ftEntity* entity = owner->m_entryManager->getEntity(entityId);
    fn_27_124364(entity->m_child, id);
}
}
