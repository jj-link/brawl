#pragma force_active on
struct Component {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void call();
};

struct Object {
    unsigned char padding[0x10];
    Component component;
};

extern "C" void fn_27_F5234(Object* self) {
    self->component.call();
}
