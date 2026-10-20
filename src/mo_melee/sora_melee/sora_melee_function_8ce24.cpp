#pragma force_active on
struct ControllerModule;

struct Inner {
    char pad[0x5c];
    ControllerModule *controller;
};

struct Mid {
    char pad[0xd8];
    Inner *inner;
};

struct StageObject {
    char pad[0x60];
    Mid *mid;
};

class soExternalValueAccesser {
public:
    static ControllerModule *getControllerModule(StageObject *stageObject);
};

ControllerModule *soExternalValueAccesser::getControllerModule(StageObject *stageObject) {
    return stageObject->mid->inner->controller;
}
