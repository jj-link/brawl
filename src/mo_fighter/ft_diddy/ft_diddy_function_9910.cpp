// The status switch table occupies a four-byte-aligned range in the REL.
#pragma section data_type ".data$diddy9910" ".bss"

#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

namespace {
struct DiddyStatusLinkEvent : soLinkEventArgs {
    explicit DiddyStatusLinkEvent(int kind) : soLinkEventArgs(kind) {}
};
}

extern "C" void fn_27_13138C(void*, int, int, soStatusData*, soModuleAccesser*);

extern "C" void fn_115_9910(void* fighter, int status, int previous,
        soStatusData* data, soModuleAccesser* accesser) {
    switch (status) {
    case 0x119: {
        DiddyStatusLinkEvent event(0x838);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    case 0x11A: {
        DiddyStatusLinkEvent event(0x839);
        accesser->m_enumerationStart->m_linkModule->sendEventNodes(1, event, 0);
        break;
    }
    }
    fn_27_13138C(fighter, status, previous, data, accesser);
}
