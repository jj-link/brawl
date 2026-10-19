#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(s32 p2, u32 p3);
};

struct Mid {
    char pad[0x64];
    Base* base;
};

struct Owner {
    char pad[0x1b4];
    Mid* mid;
};

extern "C" {
s32 fn_41_AA28(Owner* self) {
    self->mid->base->v5(0, 0x1000000F);
    return 0;
}
}
