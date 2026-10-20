#include <so/link/so_link_event_presenter.h>
#include <so/stageobject.h>
#pragma force_active on

class soModuleAccesser;

extern "C" {
void fn_122_22D0C(void*, int);
void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
}

extern "C" void fn_122_22C84(void* self, soLinkEventArgs* event,
                             soModuleAccesser* accesser, StageObject* sender,
                             int arg) {
    switch (event->m_eventKind) {
    case 0x838:
        fn_122_22D0C(self, 1);
        break;
    case 0x839:
        fn_122_22D0C(self, 0);
        break;
    }
    fn_27_1DB0F0(self, event, accesser, sender, arg);
}
