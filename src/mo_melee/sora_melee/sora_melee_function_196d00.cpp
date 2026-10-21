#pragma force_active on
class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void target();
};

extern "C" void fn_27_196D00(Object* self) {
    self->target();
}
