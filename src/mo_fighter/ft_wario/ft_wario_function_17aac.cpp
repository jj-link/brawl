#include <so/so_module_accesser.h>
#pragma force_active on

struct WarioLinkEvent : soLinkEventArgs {
    WarioLinkEvent() : soLinkEventArgs(0x839) {}
};

extern "C" void fn_110_17AAC(void*, soModuleAccesser* accesser) {
    WarioLinkEvent event;
    accesser->getLinkModule().sendEventParents(3, event);
    accesser->getKineticModule().changeKinetic(0x22, accesser);
    accesser->getWorkManageModule().offFlag(0x22000008);
}
