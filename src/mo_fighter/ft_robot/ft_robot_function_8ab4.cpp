#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

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
    virtual void v13();
    virtual void v14();
    virtual void setFloat(float value, unsigned long id);
};

struct Modules {
    char pad[0x14];
    Obj* obj;
    char pad2[0x64 - 0x18];
    Posture* posture;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

void fn_120_8AB4(void*, soModuleAccesser* accesser) {
    Obj* obj = accesser->modules->obj;
    if (obj->v3() == 0) {
        Posture* posture = accesser->modules->posture;
        float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfbf, 0);
        if (posture->getFloat(0x11000015) < limit) {
            Posture* p = accesser->modules->posture;
            p->setFloat(getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfcc, 0), 0x11000015);
        }
    }
}
}
