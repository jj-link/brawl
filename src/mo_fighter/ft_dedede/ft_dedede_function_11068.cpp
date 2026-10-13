#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" const float lbl_117_rodata_88;

namespace {
struct DededeLaunchLinkEvent : soLinkEventArgs {
    float speed;
    float angle;

    DededeLaunchLinkEvent()
        : soLinkEventArgs(0x83A), speed(lbl_117_rodata_88), angle(lbl_117_rodata_88) {}
};
}

// Send the pending launch parameters to the linked object, then clear both requests.
extern "C" void fn_117_11068(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000013)) {
        if (accesser->getLinkModule().isLinked(3) == true) {
            DededeLaunchLinkEvent event;
            event.speed = soValueAccesser::getConstantFloat(accesser, 0xFAA, 0);
            event.angle = accesser->getWorkManageModule().getFloat(0x21000004);
            accesser->getLinkModule().sendEventNodes(3, event, 0);
        }
        accesser->getWorkManageModule().offFlag(0x22000013);
        accesser->getWorkManageModule().offFlag(0x22000017);
    }
}
