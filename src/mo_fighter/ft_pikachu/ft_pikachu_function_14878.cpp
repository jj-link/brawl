#pragma force_active on
struct PikachuIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int);
};

struct PikachuMidLevel {
    char pad[0x64];
    PikachuIface* iface;
};

struct PikachuTopLevel {
    char pad[0xd8];
    PikachuMidLevel* mid;
};

struct PikachuOwner {
    char pad[0x60];
    PikachuTopLevel* top;
};

extern "C" int fn_98_14878(PikachuOwner* owner) {
    return owner->top->mid->iface->v4(0x10000007);
}
