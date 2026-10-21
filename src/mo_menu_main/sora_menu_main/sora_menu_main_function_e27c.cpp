#pragma force_active on
extern "C" void setFrameNode__8MuObjectFf(void* obj, float frame);
extern "C" void fn_1_6DA0(void* a, void* b);
extern "C" void fn_1_6DB4(void* a, void* b);

extern "C" float lbl_2_rodata_2A0;
extern "C" float lbl_2_rodata_3D8;

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getFrame();
    virtual void v7();
    virtual void setFrame(float f);
};

struct Inner {
    char pad[0xc];
    Base* base;
};

struct Obj {
    char pad[0x14];
    Inner* inner;
};

struct Self {
    char pad0[0x40];
    void* f40;
    char pad1[0x144 - 0x44];
    Obj* obj;
    char pad2[0x178 - 0x148];
    void* f178;
    char pad2b[0x180 - 0x17C];
    void* f180;
    char pad3[0x238 - 0x184];
    int field238;
};

extern "C" int fn_2_E27C(Self* self) {
    Obj* obj = self->obj;
    float f = obj->inner->base->getFrame();
    int result;
    if (f >= lbl_2_rodata_3D8) {
        setFrameNode__8MuObjectFf(obj, lbl_2_rodata_3D8);
        obj->inner->base->setFrame(lbl_2_rodata_2A0);
        fn_1_6DB4(self->f40, self->f180);
        fn_1_6DA0(self->f40, self->f178);
        result = 3;
    } else {
        result = self->field238;
    }
    return result;
}
