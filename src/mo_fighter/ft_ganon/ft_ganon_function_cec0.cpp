#pragma force_active on
struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void call(bool, bool);
};

struct Modules {
    char padding[0x3c];
    Module* module;
};

struct Fighter {
    char padding[0xd8];
    Modules* modules;
};

extern "C" void fn_109_CEC0(void*, Fighter* fighter) {
    fighter->modules->module->call(false, false);
}
