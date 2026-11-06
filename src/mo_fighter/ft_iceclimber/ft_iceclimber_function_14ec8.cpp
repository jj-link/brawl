#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on
extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Event : soLinkEventArgs {
    Event() : soLinkEventArgs(0x45b) {}
};
extern "C" void fn_105_14EC8(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000010) == true) {
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);
        if (fighter && fighter->getPartner()) {
            if (accesser->getLinkModule().isLink(6) == true) {
                Event event;
                accesser->getLinkModule().sendEventNodes(6, event, 0);
            }
        }
    }
}