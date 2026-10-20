#pragma force_active on
class soBase1 {
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
    int m0;
    int m1;
    int m2;
};

class soBase2 {
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

class soDerived : public soBase1, public soBase2 {
public:
    virtual void f10();
};

extern "C" {
void fn_27_294EC8(soDerived& r) {
    static_cast<soBase2&>(r).f8();
}
}
