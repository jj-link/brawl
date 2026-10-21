#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void call();
};

struct Object {
    char padding[0x27A8];
    Interface interface;
};

extern "C" void fn_27_28D7D4(Object* object) {
    object->interface.call();
}
