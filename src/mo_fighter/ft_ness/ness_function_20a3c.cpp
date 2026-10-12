#include <so/stageobject.h>

// Link event payloads share their kind and dispatcher word. Their trailing
// words are interpreted only after both sender kind and event kind match.
struct NessLinkEvent {
    int kind;
    unsigned int dispatcher;
    int argument;
    union {
        int value;
        bool allowSDI;
    };
};

extern "C" void fn_27_1DB0F0(void*, NessLinkEvent*, soModuleAccesser*, StageObject*, int);

extern "C" void fn_101_20A3C(void* observer, NessLinkEvent* event,
                            soModuleAccesser* accesser, StageObject* sender, int context) {
    if (sender->soGetKind() == 0 && sender->soGetSubKind() == 10) {
        switch (event->kind) {
        case 0x455: {
            soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
            soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
            if (!link->isLink(5)) {
                link->link(5, event->argument);
                work->setInt(event->value, 0x20000000);
            }
            return;
        }
        }
    } else if (sender->soGetKind() == 2 && sender->soGetSubKind() == 0x6c) {
        switch (event->kind) {
        case 0x83f:
            accesser->m_enumerationStart->m_stopModule->setHitStopFrame(
                event->argument, event->allowSDI);
            return;
        }
    }
    fn_27_1DB0F0(observer, event, accesser, sender, context);
}
