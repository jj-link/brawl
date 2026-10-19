#pragma force_active on
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v7(int a, unsigned int b);
};

struct Mid {
    char reserved[0x64];
    Base* base;
};

struct Owner {
    char reserved[0xd8];
    Mid* mid;
};

extern "C" {
int fn_122_272CC(void* unused, Owner* owner) {
    return owner->mid->base->v7(0, 0x20000003);
}
}
