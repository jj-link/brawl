#pragma force_active on
struct A {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void target();
};

struct Outer {
    int pad[4];
    A sub;
};

extern "C" void fn_27_319320(Outer* p) {
    p->sub.target();
}
