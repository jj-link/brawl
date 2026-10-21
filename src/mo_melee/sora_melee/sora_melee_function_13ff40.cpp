#pragma force_active on
struct StageObject;

class soExternalValueAccesser {
public:
    static int getSituationKind(StageObject*);
};

struct Object {
    unsigned char padding[0x114];
    StageObject* stageObject;

    StageObject* getStageObject() const {
        return stageObject;
    }
};

extern "C" int fn_27_13FF40(Object* self) {
    if (self->stageObject) {
        return soExternalValueAccesser::getSituationKind(self->getStageObject());
    }
    return -1;
}
