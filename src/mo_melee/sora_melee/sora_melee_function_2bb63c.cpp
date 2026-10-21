#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void target();
};

struct Object {
    char padding[0x10];
    Interface interface;
};

extern "C" void fn_27_2BB63C(Object* self) {
    self->interface.target();
}
