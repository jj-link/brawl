#pragma force_active on
struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void target(int);
};

struct ModuleAccessor {
    char pad[0x64];
    Module* module;
};

struct Obj {
    char pad[0xd8];
    ModuleAccessor* accessor;
};

extern "C" void fn_113_2D774(void* unused, Obj* obj) {
    obj->accessor->module->target(0x20000000);
}
