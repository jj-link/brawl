#include <so/stageobject.h>
struct GamewatchEvent : soLinkEventArgs {
    float value;
    bool flag;
};
class StopProxy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setHitStop(float, bool);
};
extern "C" void fn_27_1324D4(StageObject*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
extern "C" void fn_107_AFEC(StageObject* self, GamewatchEvent* event, soModuleAccesser* accesser, StageObject* sender, int link)
{
    if (sender->soGetKind() == 2 && sender->soGetSubKind() == 0x7a) {
        switch (event->m_eventKind) {
        case 0x838:
            accesser->getWorkManageModule().offFlag(0x12000040);
            return;
        case 0x839:
            reinterpret_cast<StopProxy*>(&self->m_moduleAccesser->getStopModule())->setHitStop((float)(int)event->value, event->flag);
            accesser->getControllerModule().setRumble(13, 0, false, -1);
            return;
        case 0x83a:
            accesser->getStatusModule().changeStatusRequest(0x138, accesser);
            return;
        }
    }
    switch (event->m_eventKind) {
    case 6:
        accesser->getWorkManageModule().offFlag(0x1200003e);
        break;
    }
    fn_27_1324D4(self, event, accesser, sender, link);
}
#pragma force_active on
extern const float lbl_107_rodata_18[] = { 3.0f, 2.0f };
#pragma force_active off
