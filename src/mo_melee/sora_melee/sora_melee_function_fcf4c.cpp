#pragma force_active on
class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Base {
public:
    virtual void g0();
    int pad[3];
};

class Outer : public Base, public Sub {
public:
    virtual void g0();
};

extern "C" {
void fn_27_FCF4C(Outer* self) {
    Sub& s = *self;
    s.f1();
}
}
