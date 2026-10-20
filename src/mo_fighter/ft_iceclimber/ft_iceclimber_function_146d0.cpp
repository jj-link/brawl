#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getLr__23soExternalValueAccesserFP11StageObject(StageObject*);
}

extern "C" void fn_105_146D0(void*, soModuleAccesser* accesser) {
    if (accesser->getLinkModule().isModelConstraint() == true) {
        int node = accesser->getLinkModule().getModelConstraintNode();
        Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(node, false);
        pos.m_z = accesser->getGroundModule().getZ();
        accesser->getLinkModule().removeModelConstraint(true);
        accesser->getLinkModule().setAttribute(
            6, (soLinkConnection::Attribute)13, true);
        accesser->getStageObject().updateNodeSRT();
        pos = accesser->getModelModule().getTopNodeGlobalPosFromNode(node, &pos);
        accesser->getPostureModule().setPos(&pos);
        accesser->getStageObject().updateNodeSRT();

        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (partner) {
                accesser->getPostureModule().setLr(
                    getLr__23soExternalValueAccesserFP11StageObject(partner));
                accesser->getPostureModule().updateRotYLr();
                accesser->getLinkModule().setAttribute(
                    6, (soLinkConnection::Attribute)12, false);
            }
        }
    }
}
