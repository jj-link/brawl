#pragma force_active on
struct Inner {
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
    char pad[0x10];
    Inner m_inner;
};

extern "C" {
void fn_27_1CF1F0(Outer* p) {
    Inner* q = &p->m_inner;
    q->f13();
}
}
