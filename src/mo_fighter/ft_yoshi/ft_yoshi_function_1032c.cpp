#pragma force_active on
struct IModule {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
};

extern "C" void fn_95_101B8(void* fighter);

extern "C" void fn_95_1032C(void* fighter) {
    char* accesser = *(char**)((char*)fighter + 0xd8);
    IModule* module = *(IModule**)(accesser + 0x70);
    module->v16();
    fn_95_101B8(fighter);
}
