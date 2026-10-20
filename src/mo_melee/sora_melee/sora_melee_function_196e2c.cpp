#pragma force_active on
class AnimObject {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void reset() = 0;
};

struct AnimState {
    unsigned int unknown;
    AnimObject* object;
    unsigned int field8;
    unsigned int fieldC;
};

extern "C" void fn_27_196E2C(AnimState* self) {
    if (self->object) {
        self->object->reset();
    }
    self->field8 = 0;
    self->fieldC = 0;
}
