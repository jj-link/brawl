#pragma force_active on
class fnBase {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
};

extern "C" {
void fn_27_C3110(fnBase* p) {
    p->fn4();
}
}
