#pragma force_active on

struct Inner {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual int v3() = 0;
};

struct Work {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void setInt(unsigned long value) = 0;
};

struct Holder {
    char pad[0x14];
    Inner* inner;
    char pad2[0x64 - 0x18];
    Work* work;
};

struct Module {
    char pad[0xd8];
    Holder* holder;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned long a, unsigned long b);
extern "C" void fn_123_1025C(void* accesser);

extern "C" void fn_123_10020(void* unused, Module* module) {
    Inner* obj = module->holder->inner;
    if (obj->v3() == 0) {
        Work* work = module->holder->work;
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(module, 0xfd6, 0);
        work->setInt(0x21000004);
    } else {
        Work* work = module->holder->work;
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(module, 0xfd7, 0);
        work->setInt(0x21000004);
    }
    fn_123_1025C(module);
}
