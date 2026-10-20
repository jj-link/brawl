#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int f6(int a);
    virtual void f7(int a, int b);
};

struct Mid {
    char pad[0x64];
    Base* obj;
};

struct Owner {
    char pad[0xd8];
    Mid* mid;
};

extern "C" int fn_95_FDD8(Owner* self) {
    Base* o = self->mid->obj;
    int n = o->f6(0x20000000);
    int r30 = 0;
    int r4 = n - 1;
    if (r4 <= 0) {
        r4 = 0;
        r30 = 1;
    }
    o->f7(r4, 0x20000000);
    return r30;
}
