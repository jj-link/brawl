#pragma force_active on
extern "C" void fn_100_F73C();

class Sub {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(unsigned int, unsigned int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21(unsigned int);
};

class Holder {
public:
    unsigned char pad[0x64];
    Sub* sub;
};

class Owner {
public:
    unsigned char pad[0xd8];
    Holder* holder;
};

extern "C" {
void fn_100_DF54(int unused, Owner* owner) {
    Sub* s = owner->holder->sub;
    s->f21(0x22000010);
    s->f7(0, 0x20000000);
    fn_100_F73C();
}
}
