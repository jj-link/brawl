#include <so/stageobject.h>
#pragma force_active on

struct FoxEvent : soLinkEventArgs {
    int value;
};
struct FoxPositionEvent : FoxEvent {
    Vec3f pos;
    float extra;
};
struct FoxParam {
    Vec3f pos;
    float extra;
};
class FoxParamTable {
public:
    virtual void unused();
    virtual FoxParam* get(int);
};
struct FoxObject {
    unsigned char pad[0x1CD48];
    FoxParamTable* table;
};
extern "C" {
void fn_27_12D904(void*, bool, bool, int);
void fn_27_1324D4(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
void fn_97_A308(Vec3f*, const Vec3f*);
}
extern "C" void fn_97_A6C8(FoxObject* self, FoxEvent* event, soModuleAccesser* accesser, StageObject* sender, int link) {
    if (sender->soGetKind() == 2) {
        if (sender->soGetSubKind() == 0x21) {
            switch (event->m_eventKind) {
            case 0x838:
                accesser->getControllerModule().resetFlickY();
                return;
            case 0x3C:
            case 0x839:
                switch (accesser->getStatusModule().getStatusKind()) {
                case 0x116:
                case 0x11D:
                case 0x11E:
                    accesser->getStatusModule().changeStatusRequest(0x11F, accesser);
                    accesser->getLinkModule().unlink(6);
                    break;
                }
                if (event->m_eventKind == 0x3C) {
                    fn_27_12D904(self, true, true, 0);
                    break;
                }
                return;
            case 0x83A: {
                accesser->getControllerModule().stopRumble(true);
                FoxEvent copy = *event;
                switch (copy.value) {
                case 0:
                    break;
                case 1:
                    accesser->getControllerModule().setRumble(2, 0, true, -1);
                    break;
                case 5:
                    accesser->getControllerModule().setRumble(15, 0, true, -1);
                    break;
                case 6:
                    accesser->getControllerModule().setRumble(8, 0, true, -1);
                    break;
                case 7:
                    accesser->getControllerModule().setRumble(5, 0, true, -1);
                    break;
                case 8:
                    accesser->getControllerModule().setRumble(14, 0, true, -1);
                    break;
                case 9:
                    break;
                }
                return;
            }
            }
        }
    }
    switch (event->m_eventKind) {
    case 0x455: {
        FoxPositionEvent* position = static_cast<FoxPositionEvent*>(event);
        fn_97_A308(&position->pos, &self->table->get(event->value)->pos);
        position->extra = self->table->get(event->value)->extra;
        break;
    }
    default:
        fn_27_1324D4(self, event, accesser, sender, link);
        break;
    }
}
