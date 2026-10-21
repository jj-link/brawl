#pragma force_active on
struct Interface {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
};

struct Object {
    unsigned char padding[16];
    Interface interface;
};

extern "C" void fn_27_D9DE4(Object* object) {
    object->interface.method3();
}
