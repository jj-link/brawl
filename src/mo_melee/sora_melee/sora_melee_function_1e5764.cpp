#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    int pad[4];
    Sub s;
};

extern "C" {
void fn_27_1E5764(Outer* o) {
    o->s.f1();
}
}
