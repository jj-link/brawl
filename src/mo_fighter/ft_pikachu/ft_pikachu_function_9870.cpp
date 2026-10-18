#pragma force_active on
struct DispatchModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void*, int);
};

struct DispatchAccessor {
    char reserved[0x64];
    DispatchModule* module;
};

struct DispatchOwner {
    char reserved[0xd8];
    DispatchAccessor* accessor;
};

extern "C" void fn_98_9870(DispatchOwner* owner, void* arg) {
    owner->accessor->module->f5(arg, 0x10000043);
}
