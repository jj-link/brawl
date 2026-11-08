#include <so/stageobject.h>
#pragma force_active on
extern "C" {
extern const float lbl_113_rodata_64;
Vec3f* fn_113_A1D0(Vec3f*, float, float, float);
void fn_113_19BA8(StageObject* self, int arg1) {
    if (self->m_moduleAccesser->getLinkModule().isModelConstraint() == 0 && arg1 == 0) return;
    Vec3f position = self->m_moduleAccesser->getModelModule().getNodeGlobalPosition(5, true);
    position.m_z = self->m_moduleAccesser->getGroundModule().getZ();
    self->m_moduleAccesser->getPostureModule().setPos(&position);
    soPostureModule* posture = &self->m_moduleAccesser->getPostureModule();
    Vec3f zero;
    posture->setRot(fn_113_A1D0(&zero, lbl_113_rodata_64, lbl_113_rodata_64, lbl_113_rodata_64), 0);
    if (self->m_moduleAccesser->getLinkModule().isModelConstraint() == 1)
        self->m_moduleAccesser->getLinkModule().removeModelConstraint(true);
    self->updateNodeSRT();
    position = self->m_moduleAccesser->getModelModule().getTopNodeGlobalPosFromNode(5, &position);
    position.m_z = self->m_moduleAccesser->getGroundModule().getZ();
    self->m_moduleAccesser->getPostureModule().setPos(&position);
}
}