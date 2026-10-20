#include <wn/weapon.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_116_data_2484[], lbl_116_data_2D00[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_116_2639C(Weapon*, unsigned int, unsigned int, unsigned int,
                  int, int, int, float, const Vec3f*, bool);
}

extern "C" bool fn_116_20134(Weapon* article, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c,
        lbl_116_data_2484, lbl_116_data_2D00, short(1)));
    Vec3f position =
        accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x1e, false);
    float facing = accesser->m_enumerationStart->m_postureModule->getLr();
    int status = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    unsigned int taskId;
    soResourceModule* resource = accesser->m_enumerationStart->m_resourceModule;
    taskId = fighter->m_taskId;
    fn_116_2639C(
        article, taskId,
        resource->getResourceIdAccesser()->getMdlResId(),
        resource->getResourceIdAccesser()->getTexResId(),
        1, 0, fn_27_111364(fighter->getOwner()),
        facing, &position, status == 0x114);
    return true;
}
