#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void target();
};

struct Object {
    unsigned char padding[12];
    Interface interface;
};

extern "C" void fn_27_1E49E0(Object* object) {
    object->interface.target();
}
