#pragma force_active on
class Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void call();
};

struct Module {
    unsigned char pad[0x18];
    Target* target;
};

struct Object {
    unsigned char pad[0x180];
    Module* module;
};

extern "C" void fn_27_2639B8(Object* object) {
    object->module->target->call();
}
