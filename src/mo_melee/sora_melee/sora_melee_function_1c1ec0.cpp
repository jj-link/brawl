#pragma force_active on
class IFace {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Base1 {
public:
    int pad[4];
};

class Derived : public Base1, public IFace {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" {
void fn_27_1C1EC0(Derived& self) {
    static_cast<IFace&>(self).f1();
}
}
