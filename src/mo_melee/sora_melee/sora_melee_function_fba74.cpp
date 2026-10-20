#pragma force_active on
class Sub {
public:
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
};

struct Outer {
    char pad[0x10];
    Sub sub;
};

extern "C" {
void fn_27_FBA74(Outer* p) {
    Sub* s = &p->sub;
    s->f8();
}
}
