#include <so/stageobject.h>

// Fighter-specific link events share the base event header and payload storage.
struct NessLinkEvent : soLinkEventArgs {
    union {
        struct { int duration; bool allowSDI; } hitStop;
        struct { float x, y, z; } position;
    } payload;
};

extern "C" {
extern const float lbl_101_rodata_8;
Vec3f* fn_101_C2CC(Vec3f*, const Vec2f&, float);
void fn_27_1324D4(StageObject*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
}

extern "C" void fn_101_C0B0(StageObject* object, NessLinkEvent* event,
                            soModuleAccesser* accesser, StageObject* sender, int link)
{
    if (sender->soGetKind() == 2) {
        switch (sender->soGetSubKind()) {
        case 0x6c:
            switch (event->m_eventKind) {
            case 0x83f:
                accesser->getStopModule().setHitStopFrame(event->payload.hitStop.duration,
                                                        event->payload.hitStop.allowSDI);
                break;
            case 0x840:
                if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
                    Vec3f result;
                    fn_101_C2CC(&result, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0), lbl_101_rodata_8);
                    event->payload.position.x = result.m_x;
                    event->payload.position.y = result.m_y;
                    event->payload.position.z = result.m_z;
                    event->_0x4 = true;
                }
                break;
            }
            return;
        case 0x66:
            switch (event->m_eventKind) {
            case 0x838:
                if (accesser->getStatusModule().getStatusKind() == 0x117) {
                    accesser->getStatusModule().changeStatusRequest(0x119, accesser);
                }
                break;
            }
            return;
        case 0x68:
            switch (event->m_eventKind) {
            case 0x838:
                if (accesser->getLinkModule().isLink(6)) {
                    accesser->getLinkModule().unlink(6);
                }
                break;
            }
            return;
        }
    }
    fn_27_1324D4(object, event, accesser, sender, link);
}
