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
    char padding[0x3C];
    Module* module;
};
struct Fighter {
    char padding[0xD8];
    Modules* modules;
};
extern "C" void fn_109_CDAC(void*, Fighter* fighter, int kind)
{
    if (kind != 0x11B)
        fighter->modules->module->call(false, false);
}
