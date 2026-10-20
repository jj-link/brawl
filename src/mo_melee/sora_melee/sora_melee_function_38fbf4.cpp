#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Outer {
    char pad[0x10];
    Sub sub;
};

extern "C" {
void fn_27_38FBF4(Outer* p) {
    p->sub.f3();
}
}
