#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_122_1D538(StageObject* object) {
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z =
        object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();

    Vec3f position = object->m_moduleAccesser->getPostureModule().getPos();
    Vec3f rotation = object->m_moduleAccesser->getPostureModule().getRot(0);

    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(
        0, &scale, &rotation, &position);
}
