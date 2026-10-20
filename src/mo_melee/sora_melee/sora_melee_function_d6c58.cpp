#pragma force_active on
typedef unsigned int u32;

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Outer {
    u32 pad[3];
    Inner inner;
};

extern "C" {
void fn_27_D6C58(Outer* p) {
    p->inner.f4();
}
}
