#include <ft/fighter.h>
#include <so/so_module_accesser.h>

namespace {
struct CaptainArticleLink {
    unsigned int taskId;
    int linkNo;
    char reserved[0x1c];
    unsigned char active : 1;
    unsigned char flags : 7;
    char padding[3];
};
template <int Kind, int Operation>
struct CaptainPositionEvent : soLinkEventArgs {
    int operation;
    Vec3f position;
    float lr;
    int reserved;
    bool updatePosition;
    Vec3f previousPosition;
    inline CaptainPositionEvent() : soLinkEventArgs(Kind), operation(Operation) {}
};
}
extern "C" {
extern CaptainArticleLink* lbl_100_bss_268;
void fn_100_FB5C(soModuleAccesser*, soLinkEventArgs*);
}

extern "C" void fn_100_ECEC(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soGroundModule* ground = &accesser->getGroundModule();
    soPostureModule* posture = &accesser->getPostureModule();
    soLinkModule* link = &accesser->getLinkModule();
    Vec3f position;
    position.m_x = work->getFloat(0x21000004);
    position.m_y = work->getFloat(0x21000005);
    position.m_z = ground->getZ();
    float lr = work->getFloat(0x21000006);
    posture->setPos(&position);
    posture->setLr(lr);
    posture->initRotYLr();
    accesser->m_stageObject->updateNodeSRT();
    int count = work->getInt(0x20000000);
    CaptainArticleLink* article = lbl_100_bss_268;
    for (int i = 0; i < count; ++i, ++article) {
        if (article->active && article->taskId != 0xffffffff) {
            CaptainPositionEvent<0x44f, 6> event;
            Vec2f center = ground->getCenterPos(0);
            event.position.m_x = work->getFloat(0x21000004);
            event.position.m_y = work->getFloat(0x21000005);
            event.position.m_z = ground->getZ();
            event.lr = work->getFloat(0x21000006);
            event.updatePosition = true;
            event.previousPosition.m_x = work->getFloat(0x21000004);
            event.previousPosition.m_y = work->getFloat(0x21000005);
            event.previousPosition.m_z = ground->getZ();
            link->sendEventParents(article->linkNo, event);
        }
    }
    CaptainPositionEvent<0x44f, 5> positionEvent;
    fn_100_FB5C(accesser, &positionEvent);
    CaptainPositionEvent<0x450, 12> rotationEvent;
    fn_100_FB5C(accesser, &rotationEvent);
    work->setInt(0, 0x20000002);
}
