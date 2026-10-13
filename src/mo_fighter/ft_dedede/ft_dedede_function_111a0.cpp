#include <so/so_module_accesser.h>

namespace {
struct DededeCancelLinkEvent : soLinkEventArgs {
    DededeCancelLinkEvent() : soLinkEventArgs(0x83B) {}
};
}

// Notify the linked object of the pending cancellation, then clear the request.
extern "C" void fn_117_111A0(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000017)) {
        if (accesser->getLinkModule().isLinked(3) == true) {
            DededeCancelLinkEvent event;
            accesser->getLinkModule().sendEventNodes(3, event, 0);
        }
        accesser->getWorkManageModule().offFlag(0x22000017);
    }
}
