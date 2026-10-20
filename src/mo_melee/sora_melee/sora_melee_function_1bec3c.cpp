#pragma force_active on
class Inner {
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

class Outer {
public:
    virtual void g();
    int a;
    int b;
    int c;
    Inner in;
};

extern "C" void fn_27_1BEC3C(Outer* o) {
    Inner* p = &o->in;
    p->f8();
}
