#pragma force_active on

class Target {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
};

struct Holder {
    Target* target;
};

struct Outer {
    unsigned char pad[0x10];
    Holder* holder;
};

extern "C" void fn_802AEFF8(Outer* self) {
    self->holder->target->s12();
}
