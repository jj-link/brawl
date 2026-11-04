#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_107_data_3D3C[], lbl_107_data_45B8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
unsigned char fn_27_1119B8(ftOwner*);
int fn_27_111364(ftOwner*);
void fn_107_1CA28(void*, unsigned int, unsigned int, int, float);
}

class ResourceIndexAccesser {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual unsigned int getIndex();
};

extern "C" bool fn_107_BA90(void* request, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_107_data_3D3C,
        lbl_107_data_45B8, short(1)));
    soResourceModule* resource = accesser->m_enumerationStart->m_resourceModule;
    unsigned int taskId = fighter->m_taskId;
    float value = fn_27_1119B8(fighter->getOwner());
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_107_1CA28(request, taskId,
        reinterpret_cast<ResourceIndexAccesser*>(resource->getResourceIdAccesser())->getIndex(), ownerId, value);
    return true;
}
