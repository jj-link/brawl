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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned long);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(unsigned long);
};

struct Modules {
    char pad0[0x20];
    Module* m20;
    char pad1[0x1c];
    Module* m40;
    char pad2[0x20];
    Module* work;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
}

extern "C" void fn_27_18446C(void*, soModuleAccesser* accesser) {
    fn_27_89DAC(3, accesser);
    fn_27_89DAC(1, accesser);
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    accesser->modules->m40->v13();
    accesser->modules->m20->v25(0);
    accesser->modules->work->v18(0x12000001);
    accesser->modules->work->v18(0x12000029);
}
