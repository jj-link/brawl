#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#include <so/so_module_accesser.h>

namespace {
struct DededeLaunchFighter {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

}

extern "C" void fn_117_1F9D4(DededeLaunchFighter* fighter, Vec3f* position,
                              float facing, float speed, float launchValue, int alternate) {
    fighter->accesser->getPostureModule().init(position, facing);
    fighter->accesser->getLinkModule().removeModelConstraint(true);
    fn_27_1DA618(fighter, 3);
    fighter->accesser->getWorkManageModule().setFloat(launchValue, 0x21000005);
    fighter->accesser->getWorkManageModule().setFloat(speed, 0x21000006);
    if (alternate != 0) {
        fighter->accesser->getStatusModule().changeStatusForce(0x10, fighter->accesser);
    } else {
        fighter->accesser->getStatusModule().changeStatusForce(2, fighter->accesser);
    }
    fighter->accesser->getAreaModule().setWhole(1);
}
