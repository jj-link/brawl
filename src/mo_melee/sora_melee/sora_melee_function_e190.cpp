#pragma force_active on
struct VBase {
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
};

extern "C" void fn_27_E190(VBase* p) {
    p->f9();
}
