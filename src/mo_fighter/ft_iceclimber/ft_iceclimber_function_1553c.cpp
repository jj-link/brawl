#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on
extern "C" void fn_105_1553C(void*, soModuleAccesser* accesser) {
    if (accesser->getLinkModule().isModelConstraint()) {
        Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(2, false);
        pos.m_z = accesser->getGroundModule().getZ();
        accesser->getLinkModule().removeModelConstraint(true);
        if (accesser->getLinkModule().isLink(6) == true)
            accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)13, true);
        accesser->getPostureModule().setPos(&pos);
        accesser->getStageObject().updateNodeSRT();
    }
}