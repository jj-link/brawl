#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void target();
};

struct Object {
    char padding[12];
    Interface interface;
};

extern "C" void fn_27_1AB734(Object* object) {
    object->interface.target();
}
