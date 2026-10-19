#pragma force_active on
struct Accessor;

struct Module {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void call(int, Accessor*);
};

struct Modules {
    char pad[0x70];
    Module* module;
};

struct Accessor {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accessor* accessor;
};

extern "C" void fn_122_20418(Object* object) {
    Accessor* accessor = object->accessor;
    accessor->modules->module->call(3, accessor);
}
