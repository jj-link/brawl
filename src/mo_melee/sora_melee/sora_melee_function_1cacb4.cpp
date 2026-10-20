#pragma force_active on
struct Sec {
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
};

struct Outer {
    int pad[4];
    Sec s;
};

extern "C" {
void fn_27_1CACB4(Outer* o) {
    o->s.f13();
}
}
