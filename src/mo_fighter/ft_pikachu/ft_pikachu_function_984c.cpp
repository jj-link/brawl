#pragma force_active on
struct PikachuTargetIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int target(int a, int b);
};

struct PikachuTargetB {
    char reserved[0x64];
    PikachuTargetIface* iface;
};

struct PikachuTargetA {
    char reserved[0xd8];
    PikachuTargetB* b;
};

struct PikachuTargetOwner {
    char reserved[0x60];
    PikachuTargetA* a;
};

extern "C" int fn_98_984C(PikachuTargetOwner* owner, int a) {
    return owner->a->b->iface->target(a, 0x10000043);
}
