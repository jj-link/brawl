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
    virtual void f15(void* a);
};

struct Mid {
    char pad[0x48];
    Sub* sub;
};

struct Arg {
    char pad[0xc];
    void* val;
};

struct Self {
    char pad[0x44];
    Mid* mid;
    Arg* a48;
    Arg* a4c;
};

extern "C" void fn_24_10D4(Self* self) {
    self->mid->sub->f15(self->a48->val);
    self->mid->sub->f15(self->a4c->val);
}
