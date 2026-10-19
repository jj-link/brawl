#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_80;

namespace {
struct KirbyLinkEvent : soLinkEventArgs {
    float speed;
    int value;
    bool flag;

    KirbyLinkEvent(int kind) : soLinkEventArgs(kind), speed(lbl_96_rodata_80), flag(false) {}
};
}

extern "C" void fn_96_169BC(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000015)) {
        accesser->getWorkManageModule().offFlag(0x22000015);
        accesser->getWorkManageModule().onFlag(0x22000016);
        KirbyLinkEvent event(0x17);
        event.value = accesser->getWorkManageModule().getInt(0x1000004a);
        accesser->getLinkModule().sendEventNodes(0, event, 0);
    }
}
