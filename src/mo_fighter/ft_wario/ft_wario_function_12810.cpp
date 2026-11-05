#include <so/so_module_accesser.h>
#pragma force_active on

struct WarioEvent : soLinkEventArgs {
    int duration;
    bool allowSDI;
    WarioEvent(int frames) : soLinkEventArgs(0x843), duration(frames), allowSDI(false) {}
};

struct WarioObject {
    unsigned char pad[0x60];
    soModuleAccesser* accesser;
};

extern "C" int fn_110_12810(WarioObject* object) {
    int duration = object->accesser->m_enumerationStart->m_workManageModule->getInt(0x10000007);
    if (duration > 0) {
        WarioEvent event(duration);
        object->accesser->m_enumerationStart->m_linkModule->sendEventParents(3, event);
        object->accesser->m_enumerationStart->m_stopModule->setHitStopFrame(duration, false);
        object->accesser->m_enumerationStart->m_workManageModule->setInt(0, 0x10000007);
    }
    return 0;
}