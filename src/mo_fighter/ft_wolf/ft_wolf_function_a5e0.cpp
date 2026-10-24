#include <so/stageobject.h>
#pragma force_active on

struct WolfEvent : soLinkEventArgs {
    int value;
    Vec3f position;
    float scale;
};

struct WolfData {
    Vec3f position;
    float scale;
};

class WolfDataArray {
public:
    virtual ~WolfDataArray();
    virtual WolfData* get(int);
};

struct WolfHandler {
    unsigned char padding[0x1CC8C];
    WolfDataArray* data;
};

extern "C" {
void fn_27_12D904(void*, bool, bool, int);
void fn_125_A220(Vec3f*, const Vec3f*);
void fn_27_1324D4(WolfHandler*, WolfEvent*, soModuleAccesser*, StageObject*, int);
}

extern "C" void fn_125_A5E0(WolfHandler* self, WolfEvent* event,
                           soModuleAccesser* accesser, StageObject* sender,
                           int link) {
    if (sender->soGetKind() == 2 && sender->soGetSubKind() == 0x21) {
        switch (event->m_eventKind) {
        case 0x838:
            accesser->getControllerModule().resetFlickY();
            return;

        case 0x839:
        case 0x3C:
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

        case 0x83A:
            accesser->getControllerModule().stopRumble(true);
            UnkLinkEvent rumble = *reinterpret_cast<UnkLinkEvent*>(event);
            switch (rumble.unk8) {
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
            case 0: case 2: case 3: case 4: case 9:
            default:
                break;
            }
            return;
        }
    }

    switch (event->m_eventKind) {
    case 0x455:
        fn_125_A220(&event->position,
                    &self->data->get(event->value)->position);
        event->scale = self->data->get(event->value)->scale;
        break;

    default:
        fn_27_1324D4(self, event, accesser, sender, link);
        break;
    }
}
