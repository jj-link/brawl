#include <so/so_module_accesser.h>

struct NessPendingHitStopEvent : soLinkEventArgs {
    int duration;
    bool allowSDI;
    NessPendingHitStopEvent(int frames)
        : soLinkEventArgs(0x83F), duration(frames), allowSDI(false) {}
};

struct NessPendingHitStopTransition {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" int fn_101_23BE0(NessPendingHitStopTransition* object) {
    int duration = object->accesser->m_enumerationStart->m_workManageModule->getInt(0x10000005);
    if (duration > 0) {
        NessPendingHitStopEvent event(duration);
        object->accesser->m_enumerationStart->m_linkModule->sendEventParents(3, event);
        object->accesser->m_enumerationStart->m_linkModule->sendEventParents(5, event);
        object->accesser->m_enumerationStart->m_stopModule->setHitStopFrame(duration, false);
        object->accesser->m_enumerationStart->m_workManageModule->setInt(0, 0x10000005);
    }
    return 0;
}
