#pragma force_active on
typedef int s32;

extern const float lbl_41_rodata_20;

struct Inner {
    virtual ~Inner();
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
    virtual float getParam(s32 id);
};

struct Mid {
    char pad[0x64];
    Inner* inner;
};

struct Outer {
    char pad[0x1b4];
    Mid* mid;
};

extern "C" float fn_41_39C0(Outer* p) {
    Inner* in = p->mid->inner;
    float a = in->getParam(0x11000001);
    float b = in->getParam(0x11000003);
    return lbl_41_rodata_20 * a / b;
}
