#pragma force_active on

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int);
};

extern "C" void fn_8018ABD8(Object* self) {
    self->slot3(0);
}
