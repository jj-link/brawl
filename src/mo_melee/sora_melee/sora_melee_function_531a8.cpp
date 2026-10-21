#pragma force_active on
class Interface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void call();
};

struct Wrapper {
    unsigned char padding[8];
    Interface* object;
};

extern "C" void fn_27_531A8(Wrapper* self) {
    self->object->call();
}
