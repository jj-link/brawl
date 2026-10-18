#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

namespace {
struct KirbySituationLinkEvent : soLinkEventArgs {
    explicit KirbySituationLinkEvent(int kind) : soLinkEventArgs(kind) {}
};
}

extern "C" void fn_96_1D8CC(void*, int, int);
extern "C" void fn_27_131CD0(void*, int, int, soModuleAccesser*);

extern "C" void fn_96_B2FC(void* fighter, int situation, int previous,
        soModuleAccesser* accesser) {
    switch (accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
    case 0x132:
        if (situation == 2) {
            KirbySituationLinkEvent event(0x839);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        } else {
            KirbySituationLinkEvent event(0x838);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        }
        break;
    }
    fn_96_1D8CC(reinterpret_cast<u8*>(fighter) + 0x1B72C, situation, previous);
    fn_27_131CD0(fighter, situation, previous, accesser);
}
