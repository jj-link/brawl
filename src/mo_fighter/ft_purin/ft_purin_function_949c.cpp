#pragma force_active on
class Module {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Object {
    unsigned char padding[0x94AC];
    Module module;
};

extern "C" void fn_124_949C(Object* object) {
    object->module.f2();
}
