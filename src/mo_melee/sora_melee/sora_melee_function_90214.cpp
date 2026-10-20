#pragma force_active on
class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

class Outer {
public:
    int m0;
    int m1;
    Sub sub;
};

extern "C" void fn_27_90214(Outer* o) {
    o->sub.f2();
}
