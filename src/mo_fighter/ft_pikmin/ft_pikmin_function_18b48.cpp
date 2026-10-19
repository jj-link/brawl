#pragma force_active on
struct FnModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void method(int value);
};

struct FnStageB {
    char pad0[0x64];
    FnModule* module;
};

struct FnStageA {
    char pad0[0xd8];
    FnStageB* b;
};

struct FnOwner {
    char pad0[0x60];
    FnStageA* a;
};

extern "C" void fn_113_18B48(FnOwner* owner)
{
    owner->a->b->module->method(0x10000005);
}
