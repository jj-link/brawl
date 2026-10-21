#pragma force_active on
extern "C" const float lbl_115_rodata_138;

struct WorkLike {
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
    virtual void setFloat(float, unsigned long);
};

struct StatusLike {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int changeStatus(int, void*);
};

struct Mod {
    char pad0[0x64];
    WorkLike* work;
    char pad1[8];
    StatusLike* status;
};

struct Accesser {
    char pad[0xD8];
    Mod* mod;
};

struct Data {
    char pad[0x28];
    float f;
};

extern "C" int fn_115_1B748(void* self, void* a2, Accesser* accesser, Data* data) {
    float v = accesser->mod->work->getFloat(0x21000003) - data->f;
    accesser->mod->work->setFloat(v, 0x21000003);
    if (v <= lbl_115_rodata_138) {
        return accesser->mod->status->changeStatus(2, accesser);
    }
    return 0;
}
