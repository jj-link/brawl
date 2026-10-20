#pragma force_active on
class Sec {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Pri {
public:
    virtual void p0();
    int a, b, c;
};

class Multi : public Pri, public Sec {
public:
    virtual void p0();
};

extern "C" void fn_27_D9CF4(Multi& p) {
    static_cast<Sec&>(p).f3();
}
