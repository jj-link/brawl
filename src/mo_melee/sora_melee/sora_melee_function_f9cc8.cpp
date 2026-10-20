#pragma force_active on
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

struct Outer {
    virtual void f0();
    int a;
    int b;
    int c;
    Sub sub;
};

extern "C" void fn_27_F9CC8(Outer* p) {
    p->sub.v8();
}
