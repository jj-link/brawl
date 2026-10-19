#pragma force_active on
struct Module {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
};

struct ModuleTable {
    char padding[0x0C];
    Module* module;
};

struct ModuleAccessor {
    char padding[0xD8];
    ModuleTable* modules;
};

struct Object {
    char padding[0x60];
    ModuleAccessor* accessor;
};

extern "C" void fn_113_189F4(Object* object) {
    object->accessor->modules->module->f10();
    object->accessor->modules->module->f19();
}
