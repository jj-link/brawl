#pragma force_active on
class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad[3];
};

class Other {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

class Derived : public Base, public Other {
public:
    virtual void g1();
};

extern "C" {
void fn_27_D87F8(Derived* self) {
    Other& o = *self;
    o.g1();
}
}
