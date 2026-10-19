#include <so/stageobject.h>
#pragma force_active on

extern "C" void fn_92_15384(Vec3f* dst, const Vec3f* src);

extern "C" void fn_92_15210(StageObject* object) {
    float maxScale = object->m_moduleAccesser->m_enumerationStart->m_workManageModule->getFloat(0x21000000);
    float scaleStep = object->m_moduleAccesser->m_enumerationStart->m_workManageModule->getFloat(0x21000001);
    float newScale = object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    newScale += scaleStep;
    if (newScale > maxScale) {
        newScale = maxScale;
    }

    Vec3f scale;
    Vec3f rotation;
    Vec3f position;
    scale.m_x = scale.m_y = scale.m_z = newScale;

    Vec3f sourcePosition = object->m_moduleAccesser->getPostureModule().getPos();
    fn_92_15384(&position, &sourcePosition);
    Vec3f sourceRotation = object->m_moduleAccesser->getPostureModule().getRot(0);
    fn_92_15384(&rotation, &sourceRotation);

    object->m_moduleAccesser->m_enumerationStart->m_postureModule->setScale(newScale);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
}
