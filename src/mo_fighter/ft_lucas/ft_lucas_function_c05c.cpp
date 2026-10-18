#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_114_data_3400[], lbl_114_data_3C7C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_114_18A44(Weapon*, unsigned int, int, const Vec3f*, float);
}

extern "C" bool fn_114_C05C(Weapon* article, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_114_data_3400,
        lbl_114_data_3C7C, short(1)));
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x27, false);
    float facing = accesser->m_enumerationStart->m_postureModule->getLr();
    taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_114_18A44(article, taskId, ownerId, &position, facing);
    accesser->m_enumerationStart->m_linkModule->link(6, article->m_taskId);
    return true;
}
