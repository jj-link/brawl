#include <so/stageobject.h>
#pragma force_active on

struct FalcoEvent : soLinkEventArgs {
    int value;
    Vec3f position;
    float extra;
};

struct FalcoRumbleEvent : soLinkEventArgs {
    int value;
};

struct FalcoData {
    Vec3f position;
    float extra;
};

class FalcoDataArray {
public:
    virtual ~FalcoDataArray();
    virtual FalcoData* get(int);
};

struct FalcoHandler {
    unsigned char padding[0x1D094];
    FalcoDataArray* data;
};

extern "C" {
void fn_27_12D904(void*, bool, bool, int);
void fn_108_A1C8(Vec3f*, const Vec3f*);
void fn_27_1324D4(FalcoHandler*, FalcoEvent*, soModuleAccesser*, StageObject*, int);
}

extern "C" void fn_108_A588(FalcoHandler* self, FalcoEvent* event,
                            soModuleAccesser* accesser, StageObject* sender,
                            int link)
{
    if (sender->soGetKind() == 2 && sender->soGetSubKind() == 0x21) {
        switch (event->m_eventKind) {
        case 0x838:
            accesser->getControllerModule().resetFlickY();
            return;
        case 0x839:
        case 0x3C:
            switch (accesser->getStatusModule().getStatusKind()) {
            case 0x116:
            case 0x11A:
            case 0x11B:
                accesser->getStatusModule().changeStatusRequest(0x11C, accesser);
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
            FalcoRumbleEvent copy = *reinterpret_cast<FalcoRumbleEvent*>(event);
            switch (copy.value) {
            case 0:
                break;
            case 1:
                accesser->getControllerModule().setRumble(2, 0, true, -1);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
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
    switch (event->m_eventKind) {
    case 0x455:
        fn_108_A1C8(&event->position, &self->data->get(event->value)->position);
        event->extra = self->data->get(event->value)->extra;
        break;
    default:
        fn_27_1324D4(self, event, accesser, sender, link);
        break;
    }
}