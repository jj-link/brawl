#include <types.h>
#pragma force_active on

class StageObject;

struct soSituationBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
    virtual void vf4();
    virtual void vf5();
};

class soExternalValueAccesser {
public:
    static int getSituationKind(StageObject* stageObj);
};

int soExternalValueAccesser::getSituationKind(StageObject* stageObj) {
    void* a = *(void**)((u8*)stageObj + 0x60);
    void* b = *(void**)((u8*)a + 0xd8);
    soSituationBase* c = *(soSituationBase**)((u8*)b + 0x14);
    return c->vf3();
}
