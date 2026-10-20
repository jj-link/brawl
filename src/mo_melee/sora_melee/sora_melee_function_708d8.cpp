#pragma force_active on
class fnBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_708D8(fnBase* p) {
    p->f1();
}
