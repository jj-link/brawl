#pragma force_active on
#include <types.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_event_presenter.h>

extern "C" int fn_27_135EE0(void*);
extern "C" u32 fn_96_1DACC(void*);

namespace {
struct KirbyLinkEvent : soLinkEventArgs {
    KirbyLinkEvent(int kind) : soLinkEventArgs(kind) {}
};
}

extern "C" int fn_96_D160(void* arg0) {
    soModuleAccesser* acc = *reinterpret_cast<soModuleAccesser**>(static_cast<u8*>(arg0) + 0x60);

    if (acc->getStatusModule().getStatusKind() == 0x112 ||
        acc->getStatusModule().getStatusKind() == 0x117) {
        if (acc->getWorkManageModule().isFlag(0x2200001A)) {
            int value = acc->getWorkManageModule().getInt(0x20000004);
            acc->getLinkModule().link(7, value);
            KirbyLinkEvent event(0x835);
            acc->getLinkModule().sendEventParents(7, event);
            if (acc->getLinkModule().isLink(7) == true) {
                acc->getLinkModule().unlink(7);
            }
            acc->getWorkManageModule().onFlag(0x2200001C);
            acc->getStatusModule().changeStatusRequest(0x126, acc);
            acc->getWorkManageModule().offFlag(0x2200001A);
            return 1;
        }
    }
    if (fn_96_1DACC(static_cast<u8*>(arg0) + 0x1B72C) == 1U) {
        return 1;
    }
    return fn_27_135EE0(arg0);
}
