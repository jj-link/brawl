// The status switch table occupies a four-byte-aligned range in the REL.
#pragma section data_type ".data$dedede99E4" ".bss"

#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>

namespace {
struct DededeStatusLinkEvent : soLinkEventArgs {
    explicit DededeStatusLinkEvent(int kind) : soLinkEventArgs(kind) {}
};
}

extern "C" void fn_27_13138C(void*, int, int, soStatusData*, soModuleAccesser*);

extern "C" void fn_117_99E4(void* fighter, int status, int previous,
        soStatusData* data, soModuleAccesser* accesser) {
    switch (status) {
    case 0x115: {
        DededeStatusLinkEvent event(0x83A);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x12F: {
        DededeStatusLinkEvent event(0x83B);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x130: {
        DededeStatusLinkEvent event(0x83C);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x131: {
        DededeStatusLinkEvent event(0x83D);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x132: {
        DededeStatusLinkEvent event(0x83E);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x133: {
        DededeStatusLinkEvent event(0x83F);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x134: {
        DededeStatusLinkEvent event(0x840);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x135: {
        DededeStatusLinkEvent event(0x841);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x136: {
        DededeStatusLinkEvent event(0x842);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x137: {
        DededeStatusLinkEvent event(0x843);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    }
    switch (previous) {
    case 0x116:
    case 0x138:
    case 0x139:
        if (status != 0x138 && status != 0x139) {
            DededeStatusLinkEvent event(0x83C);
            accesser->m_enumerationStart->m_linkModule->sendEventNodes(-1, event, 0);
        }
        break;
    }
    fn_27_13138C(fighter, status, previous, data, accesser);
}
