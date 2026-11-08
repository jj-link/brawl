#include <so/stageobject.h>
#pragma force_active on
extern "C" void fn_98_1B69C(StageObject* self) {
 soModuleAccesser* a = self->m_moduleAccesser;
 soPostureModule* p = a->m_enumerationStart->m_postureModule;
 Vec3f position = p->getPos();
 Vec3f rotation = p->getRot(0);
 Vec3f scale;
 float s = p->getScale();
 scale.m_x = s; scale.m_y = s; scale.m_z = s;
 position.m_z = a->m_enumerationStart->m_groundModule->getZ();
 a->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
}
