#pragma force_active on
struct Posture {
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
    virtual float getFloat(unsigned long id);
    virtual void setFloat(float value, unsigned long id);
};

struct Modules {
    char pad[0x64];
    Posture* posture;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
}

extern "C" void fn_123_1025C(soModuleAccesser* accesser) {
    Posture* posture = accesser->modules->posture;
    float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfd8, 0);
    if (posture->getFloat(0x21000004) > limit) {
        Posture* p = accesser->modules->posture;
        p->setFloat(
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xfd8, 0),
            0x21000004);
    }
}
