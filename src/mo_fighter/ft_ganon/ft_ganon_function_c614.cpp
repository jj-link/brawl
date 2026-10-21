#pragma force_active on

struct ModuleEnumeration {
    char pad1[0x14];
    void* situationModule;
    char pad2[0x4C];
    void* workModule;
};

struct ModuleAccesser {
    char pad[0xD8];
    const ModuleEnumeration* enumerationStart;
};

struct SituationModule {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual int v3() = 0;
};

struct WorkModule {
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
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual int v17(unsigned long) = 0;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
void fn_109_D00C(void*, float, float);
}

extern "C" void fn_109_C614(void* unused, ModuleAccesser* accesser) {
    const ModuleEnumeration* e = accesser->enumerationStart;
    WorkModule* work = (WorkModule*)e->workModule;
    SituationModule* situation = (SituationModule*)e->situationModule;

    if (situation->v3() == 2 && work->v17(0x22000011) != 0) {
        float f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFA6, 0);
        float f2 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFA7, 0);
        fn_109_D00C(accesser, f1, f2);
    }
}
