#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

struct RobotLinkFighter {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_120_1387C(RobotLinkFighter* fighter, soLinkEventArgs* event,
                            soModuleAccesser* accesser, StageObject* object, int value) {
    switch (event->m_eventKind) {
    case 0x839:
        if (accesser->getStatusModule().getStatusKind() == 0)
            fighter->accesser->getStatusModule().changeStatusRequest(1, fighter->accesser);
        break;
    case 0x83A:
        fighter->accesser->getStatusModule().changeStatusRequest(2, fighter->accesser);
        break;
    }
    fn_27_1DB0F0(fighter, event, accesser, object, value);
}
