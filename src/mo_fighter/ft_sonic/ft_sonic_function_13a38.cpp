#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_123_13A38(StageObject* object) {
    Vec3f scale;
    scale.m_z = scale.m_y = scale.m_x = object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    Vec3f position = object->m_moduleAccesser->getPostureModule().getPos();
    Vec3f rotation = object->m_moduleAccesser->getPostureModule().getRot(0);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeRotate(4, &rotation);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeScale(0, &scale);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeTranslate(0, &position);
}
