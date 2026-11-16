#pragma force_active on

#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <types.h>

extern "C" {
extern const char lbl_122_data_83E4[], lbl_122_data_8C98[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_27_3AE060(void*, int, int, float, int);
}

extern "C" int fn_122_DDF8(void* owner, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_122_data_83E4, lbl_122_data_8C98,
        short(1)));
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soResourceModule* resourceModule = modules->m_resourceModule;
    float facing = modules->m_postureModule->getLr();
    int ownerId = fn_27_111364(fighter->getOwner());
    unsigned int resource = resourceModule->getResourceIdAccesser()->getEtcResId();
    fn_27_3AE060(owner, resource, ownerId, facing, taskId);
    return 1;
}