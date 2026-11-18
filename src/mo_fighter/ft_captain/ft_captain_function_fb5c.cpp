#include <so/so_module_accesser.h>
#pragma force_active on
struct CaptainFinalHit {
    unsigned int taskId;
    int linkIndex;
    unsigned char reserved08[8];
    int kind;
    unsigned char reserved14[0x10];
    bool active : 1;
    unsigned char flags : 7;
    unsigned char padding[3];
};
extern "C" {
extern CaptainFinalHit* lbl_100_bss_268;
void fn_100_FB5C(soModuleAccesser* accesser, soLinkEventArgs* event) {
    soLinkModule* link;
    int i;
    CaptainFinalHit* hit;
    bool kind;
    int count;
    soWorkManageModule* work;
    work = &accesser->getWorkManageModule();
    link = &accesser->getLinkModule();
    kind = event->m_eventKind == 0x44f;
    count = work->getInt(0x20000000);
    hit = lbl_100_bss_268;
    for (i = 0; i < count; ++i, ++hit) {
        if (hit->active == kind && (unsigned)(hit->taskId + 0x10000) != 0xFFFF) {
            link->sendEventParents(hit->linkIndex, *event);
        }
    }
}
}
