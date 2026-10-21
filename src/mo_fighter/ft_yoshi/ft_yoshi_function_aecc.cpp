#pragma force_active on

struct Work {
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
    virtual float getFloat(unsigned long);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int onFlag(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
void fn_27_20084(void*, float);
extern const float lbl_95_rodata_4;
extern const float lbl_95_rodata_20;

void fn_95_AECC(Fighter* self) {
    Accesser* acc = self->accesser;
    if (acc->modules->work->onFlag(0x1200003D) != 0) {
        Work* w = acc->modules->work;
        float d = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xca1, 0);
        float v = lbl_95_rodata_4 - (w->getFloat(0x11000003) / d);
        v = lbl_95_rodata_20 * v;
        fn_27_20084((unsigned char*)self + 0x22288, v);
    }
}
}
