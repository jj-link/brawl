#pragma force_active on

struct Work {
    int a;
    int b;
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void getConstantVec(unsigned long, float*);
};

struct Modules {
    char pad[4];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

extern "C" void fn_121_10FB0(void*, Accesser* accesser) {
    float data[3];
    data[0] = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb1, 0);
    data[1] = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb2, 0);
    data[2] = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb3, 0);
    accesser->modules->work->getConstantVec(0xfd, data);
}
