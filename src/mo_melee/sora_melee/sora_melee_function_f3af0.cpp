#pragma force_active on
class Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Pad {
public:
    int a;
    int b;
    int c;
    int d;
};

class Derived : public Pad, public Iface {
public:
};

extern "C" {
void fn_27_F3AF0(Derived& self) {
    static_cast<Iface&>(self).f1();
}
}
