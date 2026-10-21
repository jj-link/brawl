#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_101_2499C(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soGroundModule* ground = modules->m_groundModule;
    soPostureModule* posture = modules->m_postureModule;

    Vec3f pos = posture->getPos();
    Vec3f correct = ground->getCorrectPos(0);
    if (ground->isTouch(9, 0)) {
        pos.m_y = correct.m_y;
    }
    if (ground->isTouch(6, 0)) {
        pos.m_x = correct.m_x;
    }
    posture->setPos(&pos);
    accesser->m_stageObject->updateNodeSRT();
}
