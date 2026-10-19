#pragma force_active on
class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" {
bool fn_56_AF10(Base* p) {
    return !p->f3();
}
}
