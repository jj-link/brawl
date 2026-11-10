#include <so/stageobject.h>
#include <so/posture/so_posture_module_simple.h>
#pragma force_active on

extern "C" void fn_120_13860(Vec3f* destination, const Vec3f* source);

extern "C" void fn_120_13788(StageObject* object) {
    Vec3f scale;
    Vec3f rotation;
    Vec3f position;
    scale.m_x = scale.m_y = scale.m_z = object->m_moduleAccesser->getPostureModule().getScale();
    Vec3f sourcePosition = object->m_moduleAccesser->getPostureModule().getPos();
    fn_120_13860(&position, &sourcePosition);
    Vec3f sourceRotation = object->m_moduleAccesser->getPostureModule().getRot(0);
    fn_120_13860(&rotation, &sourceRotation);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
}
