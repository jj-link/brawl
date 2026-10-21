#pragma force_active on
class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" {
int fn_8019BAD4(Base* arg0) {
    return arg0->f3() + 4;
}
}
