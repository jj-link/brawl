#include <so/stageobject.h>
#pragma force_active on

extern "C" {
extern f32 lbl_122_rodata_158;
}

extern "C" void fn_122_264A8(StageObject* object) {
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z =
        object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    Vec3f position = object->m_moduleAccesser->getPostureModule().getPos();
    Vec3f rotation = object->m_moduleAccesser->getPostureModule().getRot(1);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);

    Vec3f rot0 = object->m_moduleAccesser->getPostureModule().getRot(0);
    if (rot0.m_z >= lbl_122_rodata_158) {
        rot0.m_z -= lbl_122_rodata_158;
        object->m_moduleAccesser->getPostureModule().setRot(&rot0, 0);
    }
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeRotate(1, &rot0);
}
