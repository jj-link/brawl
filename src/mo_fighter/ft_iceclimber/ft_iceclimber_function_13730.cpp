#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getLr__23soExternalValueAccesserFP11StageObject(StageObject*);
extern float lbl_105_rodata_40;
}

extern "C" void fn_105_13730(void*, soModuleAccesser* accesser) {
    Fighter* fighter = (Fighter*)__dynamic_cast(
        &accesser->getStageObject(), 0x3c,
        lbl_105_data_698, lbl_105_data_3860, 0);
    if (fighter) {
        Fighter* partner = fighter->getPartner();
        if (partner) {
            if (accesser->getLinkModule().isLink(6) == true) {
                accesser->getLinkModule().setModelConstraintPosOrt(6, 0, 0, 3, true);
                accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)0, true);
                accesser->getLinkModule().setAttribute(6, (soLinkConnection::Attribute)12, true);
            }
            accesser->getPostureModule().setLr(
                lbl_105_rodata_40 * getLr__23soExternalValueAccesserFP11StageObject(partner));
        }
    }
}
