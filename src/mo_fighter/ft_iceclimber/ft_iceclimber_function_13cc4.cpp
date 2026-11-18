#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" void fn_105_13CC4(soModuleAccesser* accesser) {
    if (accesser->getLinkModule().isModelConstraint()) {
        Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(2, false);
        pos.m_z = accesser->getGroundModule().getZ();
        accesser->getLinkModule().removeModelConstraint(true);
        accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)13, true);
        accesser->getPostureModule().setPos(&pos);
        accesser->getStageObject().updateNodeSRT();
        accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)12, false);
    }
}