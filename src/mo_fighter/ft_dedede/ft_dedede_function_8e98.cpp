#include <wn/weapon.h>
#include <so/so_module_accesser.h>

extern "C" void fn_117_1A178(StageObject*, unsigned int, int, float);

extern "C" bool fn_117_8E98(Weapon* article, soModuleAccesser* accesser) {
    soResourceModule* resource = accesser->m_enumerationStart->m_resourceModule;
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    float facing = accesser->m_enumerationStart->m_postureModule->getLr();
    fn_117_1A178(article, taskId, resource->getResourceIdAccesser()->getMdlResId(), facing);
    return true;
}
