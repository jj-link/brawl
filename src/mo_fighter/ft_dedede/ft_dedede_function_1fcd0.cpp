#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>

struct DededeLinkParameters {
    unsigned char prefix[8];
    u32 nodeId;
};
struct DededeLinkFighter {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x58];
    DededeLinkParameters* parameters;
};
struct DededeLinkPositionEvent : soLinkEventArgs {
    float x;
    float y;
};

extern "C" void fn_117_1FCD0(DededeLinkFighter* fighter, soLinkEventArgs* event,
                             soModuleAccesser* accesser, StageObject* object, int value) {
    switch (event->m_eventKind) {
    case 0x838:
        fighter->accesser->getWorkManageModule().offFlag(0x22000002);
        fighter->accesser->getWorkManageModule().onFlag(0x22000001);
        break;
    case 0x839:
        fighter->accesser->getWorkManageModule().onFlag(0x22000002);
        fighter->accesser->getWorkManageModule().onFlag(0x22000001);
        break;
    case 0x83C:
        if (fighter->accesser->getWorkManageModule().isFlag(0x22000005))
            fighter->accesser->getWorkManageModule().onFlag(0x22000004);
        break;
    case 0x83A:
        if (accesser->getStatusModule().getStatusKind() == 1) {
            Vec3f position = fighter->accesser->getLinkModule().getParentModelNodeGlobalPosition(
                3, fighter->parameters->nodeId, true);
            position.m_z = fighter->accesser->getGroundModule().getZ();
            float lr = fighter->accesser->getLinkModule().getParentLr(3);
            fighter->accesser->getPostureModule().init(&position, lr);
            fighter->accesser->getLinkModule().removeModelConstraint(true);
            DededeLinkPositionEvent* positionEvent = static_cast<DededeLinkPositionEvent*>(event);
            fighter->accesser->getWorkManageModule().setFloat(positionEvent->y, 0x21000005);
            fighter->accesser->getWorkManageModule().setFloat(positionEvent->x, 0x21000006);
            fn_27_1DA618(fighter, 3);
            fighter->accesser->getStatusModule().changeStatusForce(2, fighter->accesser);
        }
        break;
    case 0x83B:
        if (accesser->getStatusModule().getStatusKind() == 1) {
            Vec3f position = fighter->accesser->getLinkModule().getParentModelNodeGlobalPosition(
                3, fighter->parameters->nodeId, true);
            position.m_z = fighter->accesser->getGroundModule().getZ();
            float lr = fighter->accesser->getLinkModule().getParentLr(3);
            fighter->accesser->getPostureModule().init(&position, lr);
            fighter->accesser->getLinkModule().removeModelConstraint(true);
            fn_27_1DA618(fighter, 3);
            fighter->accesser->getStatusModule().changeStatusForce(0x10, fighter->accesser);
        }
        break;
    }
    fn_27_1DB0F0(fighter, event, accesser, object, value);
}
