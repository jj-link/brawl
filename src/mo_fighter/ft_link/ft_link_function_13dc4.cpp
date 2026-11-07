#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_93_F174(Vec3f*, const Vec3f*);

extern "C" void fn_93_13DC4(StageObject* object) {
    Vec3f scale;
    Vec3f rotation;
    Vec3f rotation1;
    Vec3f position;
    scale.m_x = scale.m_y = scale.m_z = object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    Vec3f sourcePosition = object->m_moduleAccesser->getPostureModule().getPos();
    fn_93_F174(&position, &sourcePosition);
    Vec3f sourceRotation = object->m_moduleAccesser->getPostureModule().getRot(0);
    fn_93_F174(&rotation, &sourceRotation);
    Vec3f sourceRotation1 = object->m_moduleAccesser->getPostureModule().getRot(1);
    fn_93_F174(&rotation1, &sourceRotation1);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeRotate(1, &rotation1);
}
