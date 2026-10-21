#pragma force_active on
struct StatusModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};
struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFloat(float value, unsigned long id);
};
struct Modules {
    char pad0[0x14];
    StatusModule* status;
    char pad1[0x4c];
    WorkModule* work;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" int fn_27_1922CC(Accesser*, unsigned long);
extern "C" void fn_27_324808(void*, Accesser* accesser) {
    if (accesser->modules->status->getKind() == 2) {
        int v = fn_27_1922CC(accesser, 0x5dc0);
        accesser->modules->work->setFloat(v, 0x11000000);
    }
}
