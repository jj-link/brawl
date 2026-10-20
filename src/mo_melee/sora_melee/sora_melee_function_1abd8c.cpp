#pragma force_active on
struct A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    int pad[4];
    A m_a;
};

extern "C" {
void fn_27_1ABD8C(Outer* o) {
    o->m_a.f1();
}
}
