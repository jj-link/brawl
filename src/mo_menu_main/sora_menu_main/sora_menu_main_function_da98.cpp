#pragma force_active on
extern "C" void fn_1_6DB4(void*, void*);
extern "C" void fn_1_6DA0(void*, void*);
extern "C" void setFrameNode__8MuObjectFf(void*, float);
extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern "C" float lbl_2_rodata_2A0;
extern "C" float lbl_2_rodata_350;

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float);
};

struct Inner {
    char pad[0xc];
    Base* base;
};

struct MuObject {
    char pad[0x14];
    Inner* inner;
};

struct Self {
    char pad0[0x40];
    void* f40;
    unsigned char flag;
    char pad1[0x144 - 0x45];
    MuObject* obj144;
    MuObject* obj148;
    char pad2[0x178 - 0x14C];
    void* f178;
    char pad2b[0x180 - 0x17C];
    void* f180;
    char pad3[0x254 - 0x184];
    int field254;
};

extern "C" void fn_2_DA98(Self* self) {
    fn_1_6DB4(self->f40, self->f178);
    MuObject* obj = self->obj144;
    setFrameNode__8MuObjectFf(obj, lbl_2_rodata_2A0);
    obj->inner->base->setFrame(lbl_2_rodata_350);
    int idx = self->flag;
    self->field254 = idx;
    MuObject* obj2 = self->obj148;
    float f = (float)idx;
    setFrameNode__8MuObjectFf(obj2, f);
    setFrameVisible__8MuObjectFf(obj2, f);
    fn_1_6DA0(self->f40, self->f180);
}
