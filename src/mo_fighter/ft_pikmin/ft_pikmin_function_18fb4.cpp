#pragma force_active on

struct StatusModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int f16();
};

struct Inner {
    char pad[0x70];
    StatusModule* status;
};

struct Mid {
    char pad[0xD8];
    Inner* inner;
};

struct Outer {
    char pad[0x60];
    Mid* mid;
};

extern "C" int fn_113_18FB4(Outer* self) {
    switch (self->mid->inner->status->f16()) {
    case 16:
    case 19:
    case 21:
    case 28:
        return 1;
    default:
        return 0;
    }
}
