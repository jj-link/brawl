#pragma force_active on
class soBaseIface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class soPad {
public:
    int m_pad[4];
};

class soDerived : public soPad, public soBaseIface {
public:
    virtual void f5();
};

extern "C" {
void fn_27_1B1458(soDerived* p) {
    soBaseIface& b = *p;
    b.f3();
}
}
