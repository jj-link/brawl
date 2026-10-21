#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void invoke();
};

struct Module {
    unsigned char padding[0x58];
    Target* target;
};

struct ModuleAccess {
    unsigned char padding[0xD8];
    Module* module;
};

struct Object {
    unsigned char padding[0x60];
    ModuleAccess* access;
};

extern "C" void fn_27_1DA550(Object* object) {
    object->access->module->target->invoke();
}
