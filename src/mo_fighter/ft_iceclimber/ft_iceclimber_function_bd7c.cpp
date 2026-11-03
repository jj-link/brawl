#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/link/so_link_event_presenter.h>
#pragma force_active on

namespace {
struct FlagLinkEvent : soLinkEventArgs {
    bool flag;

    FlagLinkEvent(bool f) : soLinkEventArgs(0x462), flag(f) {}
};

struct ParamLinkEvent : soLinkEventArgs {
    int value;
    bool flag;

    ParamLinkEvent(int v) : soLinkEventArgs(0x456), value(v), flag(false) {}
};
}

extern "C" void fn_105_BD7C(void* a0, int a1, void* a2, void* a3, soModuleAccesser* accesser) {
    if (accesser->getLinkModule().isLink(6) == true) {
        soModuleAccesser* other = *reinterpret_cast<soModuleAccesser**>(reinterpret_cast<char*>(a0) + 0x60);
        if (other->getWorkManageModule().isFlag(0x1200003E) == false) {
            int kind = -1;
            switch (a1) {
            case 0x1C2:
                kind = 0x1EA;
                break;
            case 0x1C3:
                kind = 0x1EB;
                break;
            case 0x1C5:
                kind = 0x1EC;
                break;
            case 0x1C7:
                kind = 0x1EE;
                break;
            case 0x1C9:
                kind = 0x1F0;
                break;
            case 0x1D3:
            case 0x1D8:
            case 0x1E4: {
                FlagLinkEvent event(true);
                accesser->getLinkModule().sendEventNodes(6, event, 0);
                return;
            }
            case 0x1D5:
            case 0x1D9:
            case 0x1E8: {
                FlagLinkEvent event(false);
                accesser->getLinkModule().sendEventNodes(6, event, 0);
                return;
            }
            }
            if (kind != -1) {
                ParamLinkEvent event(kind);
                accesser->getLinkModule().sendEventNodes(6, event, 0);
            }
        }
    }
}
