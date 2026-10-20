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

struct PositionEvent : soLinkEventArgs {
    Vec3f pos;

    PositionEvent(const Vec3f& value) : soLinkEventArgs(0x459), pos(value) {}
};
}

extern "C" void fn_105_14974(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000010) == true) {
        accesser->getWorkManageModule().offFlag(0x22000010);
        Fighter* fighter = (Fighter*)__dynamic_cast(
            &accesser->getStageObject(), 0x3c,
            lbl_105_data_698, lbl_105_data_3860, 0);

        if (fighter) {
            Fighter* partner = fighter->getPartner();
            if (partner &&
                getStatusKind__23soExternalValueAccesserFP11StageObject(partner) == 0x119) {
                if (accesser->getLinkModule().isLink(6) == true) {
                    StatusEvent status(0x11f);
                    accesser->getLinkModule().sendEventNodes(6, status, 0);

                    PositionEvent position(accesser->getGroundModule().getCliffPos(0));
                    accesser->getLinkModule().sendEventNodes(6, position, 0);
                }
            }
        }
    }
}
