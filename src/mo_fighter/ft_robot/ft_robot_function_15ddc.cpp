#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

struct RobotLinkFighter {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_120_15DDC(RobotLinkFighter* fighter, soLinkEventArgs* event,
                            soModuleAccesser* accesser, StageObject* object, int value) {
    switch (event->m_eventKind) {
    case 0x839:
        if (accesser->getStatusModule().getStatusKind() == 0)
            fighter->accesser->getStatusModule().changeStatusRequest(1, fighter->accesser);
        break;
    case 0x83B:
        fighter->accesser->getStatusModule().changeStatusRequest(2, fighter->accesser);
        break;
    case 0x83C:
        fighter->accesser->getWorkManageModule().offFlag(0x22000002);
        fighter->accesser->getWorkManageModule().onFlag(0x22000001);
        break;
    case 0x83D:
        fighter->accesser->getWorkManageModule().onFlag(0x22000002);
        fighter->accesser->getWorkManageModule().onFlag(0x22000001);
        break;
    }
    fn_27_1DB0F0(fighter, event, accesser, object, value);
}
