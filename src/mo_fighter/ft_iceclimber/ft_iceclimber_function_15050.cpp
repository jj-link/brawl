#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_105_15050(void*, soModuleAccesser* accesser) {
    Fighter* fighter = (Fighter*)__dynamic_cast(
        &accesser->getStageObject(), 0x3c,
        lbl_105_data_698, lbl_105_data_3860, 0);
    if (fighter) {
        Fighter* partner = fighter->getPartner();
        if (partner) {
            if (accesser->getLinkModule().isLink(6) == true) {
                accesser->getLinkModule().setModelConstraintPosOrt(6, 0, 0, 3, true);
            }
            accesser->getPostureModule().setLr(soExternalValueAccesser::getLr(partner));
        }
    }
}
