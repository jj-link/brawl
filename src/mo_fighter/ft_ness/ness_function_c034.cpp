#pragma force_active on
class NessStatusModule {
public:
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
    virtual void setStatus(int, int, int);
};

struct NessModuleAccesser {
    unsigned char pad[0x28];
    NessStatusModule* status;
};

struct NessModules {
    unsigned char pad[0xD8];
    NessModuleAccesser* accesser;
};

struct Ness {
    unsigned char pad0[0x60];
    NessModules* modules;
    unsigned char pad1[0x4AE24 - 0x64];
    unsigned char flag0;
    unsigned char flag1;
};

extern "C" int fn_27_135DE8(void*);

extern "C" int fn_101_C034(Ness* self) {
    if (self->flag0 == 1) {
        return 1;
    }
    if (self->flag1 == 1) {
        self->modules->accesser->status->setStatus(0, 0, 2);
    }
    return fn_27_135DE8(self);
}
