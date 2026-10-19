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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void slot18(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Accesser* accesser;
};

struct Arg {
    char pad[0xc];
    float value;
};

extern "C" {
void fn_27_13604C(void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

void fn_113_C318(Self* self, Arg* arg) {
    fn_27_13604C(self);
    float v = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self->accesser, 0xfad, 0);
    if (arg->value >= v) {
        self->accesser->modules->work->slot18(0x22000018);
    }
}
}
