#pragma force_active on
struct TypeA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(float);
    virtual float v6(float);
};

struct TypeB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int);
};

struct Mid {
    char pad[0x14];
    TypeA* objA;
};

struct Self {
    char pad[0x10];
    TypeB* objB;
    Mid* mid;
};

extern "C" {
void fn_800B798C(Self* self, float f) {
    if (f != self->mid->objA->v6(f)) {
        self->objB->v6(3, 0);
    }
    self->mid->objA->v5(f);
}
}
