#pragma force_active on
struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void target();
};

struct Object {
    char padding[12];
    Interface interface;
};

extern "C" void fn_27_D71C8(Object* self) {
    self->interface.target();
}
