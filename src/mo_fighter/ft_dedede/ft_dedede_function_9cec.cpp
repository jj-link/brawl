#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>

namespace {
struct DededeSituationLinkEvent : soLinkEventArgs {
    explicit DededeSituationLinkEvent(int kind) : soLinkEventArgs(kind) {}
};
}

extern "C" void fn_27_131CD0(void*, int, int, soModuleAccesser*);

extern "C" void fn_117_9CEC(void* fighter, int situation, int previous,
        soModuleAccesser* accesser) {
    switch (accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
    case 0x113:
    case 0x129:
        if (situation == 0) {
            DededeSituationLinkEvent event(0x838);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        } else {
            DededeSituationLinkEvent event(0x839);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        }
        break;
    case 0x115:
    case 0x12F:
    case 0x130:
    case 0x131:
    case 0x132:
    case 0x133:
    case 0x134:
    case 0x135:
    case 0x136:
    case 0x137:
        if (situation == 0) {
            DededeSituationLinkEvent event(0x838);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        } else {
            DededeSituationLinkEvent event(0x839);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        }
        break;
    }
    fn_27_131CD0(fighter, situation, previous, accesser);
}
