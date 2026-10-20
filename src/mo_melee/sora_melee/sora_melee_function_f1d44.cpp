#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    int a[4];
    Inner in;
};

extern "C" {
void fn_27_F1D44(Outer* p) {
    p->in.f1();
}
}
