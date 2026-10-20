#pragma force_active on
class Iface {
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
};

class Pad {
public:
    int pad[4];
};

class Derived : public Pad, public Iface {
};

extern "C" void fn_27_1C1DB0(Derived* p) {
    p->f8();
}
