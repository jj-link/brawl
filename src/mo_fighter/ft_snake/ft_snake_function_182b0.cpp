#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_122_182B0(StageObject* object) {
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z =
        object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();

    Vec3f position = object->m_moduleAccesser->getPostureModule().getPos();
    Vec3f rotation = object->m_moduleAccesser->getPostureModule().getRot(0);

    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(
        0, &scale, &rotation, &position);

    u32 flag = 0;
    int statusKind = object->m_moduleAccesser->m_enumerationStart->m_statusModule->getStatusKind();

    switch (statusKind) {
        case 5:
            flag = 1;
            break;
        case 1:
            if (object->m_moduleAccesser->m_enumerationStart->m_workManageModule->isFlag(0x22000000)) {
                flag = 1;
            }
            break;
        case 2:
            if (object->m_moduleAccesser->m_enumerationStart->m_workManageModule->isFlag(0x22000000)) {
                flag = 1;
            }
            break;
    }

    if (flag == 1) {
        object->m_moduleAccesser->getPostureModule().getRot(1);
    }
}
