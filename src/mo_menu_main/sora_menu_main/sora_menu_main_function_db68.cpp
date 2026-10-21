#pragma force_active on
extern "C" void setFrameNode__8MuObjectFf(void* obj, float frame);

extern "C" float lbl_2_rodata_3D0;
extern "C" float lbl_2_rodata_2A0;

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
    char pad[0x144];
    Obj* obj;
    char pad2[0x238 - 0x148];
    int field238;
};

extern "C" int fn_2_DB68(Self* self) {
    Obj* obj = self->obj;
    float f = obj->inner->base->getFrame();
    int result;
    if (f >= lbl_2_rodata_3D0) {
        setFrameNode__8MuObjectFf(obj, lbl_2_rodata_3D0);
        obj->inner->base->setFrame(lbl_2_rodata_2A0);
        result = 10;
    } else {
        result = self->field238;
    }
    return result;
}
