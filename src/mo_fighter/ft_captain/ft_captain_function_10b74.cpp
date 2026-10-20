#include <so/so_module_accesser.h>
#pragma force_active on

struct CaptainFinalHit {
    unsigned int taskId;
    int linkIndex;
    unsigned char reserved08[8];
    int kind;
    unsigned char reserved14[0x10];
    unsigned char active : 1;
    unsigned char flags : 7;
    unsigned char padding[3];
};

template <int Operation>
struct CaptainFinalEvent : soLinkEventArgs {
    int operation;
    unsigned char payload[0x24];

    CaptainFinalEvent() : soLinkEventArgs(0x450), operation(Operation) {}
};

extern "C" {
extern CaptainFinalHit* lbl_100_bss_268;

void fn_100_10B74(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soLinkModule* link = &accesser->getLinkModule();
    int count = work->getInt(0x20000000);
    int i;
    CaptainFinalHit* hit = lbl_100_bss_268;

    for (i = 0; i < count; ++i, ++hit) {
        if (hit->taskId != 0xFFFFFFFF && !hit->active) {
            if (hit->kind == 5) {
                CaptainFinalEvent<14> event;
                link->sendEventParents(hit->linkIndex, event);
            } else {
                CaptainFinalEvent<13> event;
                link->sendEventParents(hit->linkIndex, event);
            }
        }
    }
}
}
