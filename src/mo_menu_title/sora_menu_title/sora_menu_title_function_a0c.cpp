#pragma force_active on
struct Sub {
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
    virtual void f13(void* a);
    virtual void f14();
    virtual void f15();
};

struct Arg {
    char pad[0xc];
    void* val;
};

struct Mid {
    char pad[0x48];
    Sub* sub;
};

struct Self {
    char pad[0x44];
    Mid* mid;
    Arg* arg;
};

extern "C" void fn_24_A0C(Self* self) {
    self->mid->sub->f13(self->arg->val);
}
