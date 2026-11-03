#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);
}

namespace {
struct StatusEvent : soLinkEventArgs {
    int status;

    StatusEvent(int value) : soLinkEventArgs(0x455), status(value) {}
};
}

extern "C" void fn_105_142FC(void*, soModuleAccesser* accesser, int kind) {
    if (kind != 0x119) {
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (partner &&
                getStatusKind__23soExternalValueAccesserFP11StageObject(partner) == 0x11a) {
                if (accesser->getLinkModule().isLink(6) == true) {
                    StatusEvent status(0xE);
                    accesser->getLinkModule().sendEventNodes(6, status, 0);
                }
            }
        }
    }
}
