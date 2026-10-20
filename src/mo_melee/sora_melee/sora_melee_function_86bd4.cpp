#pragma force_active on
class fnBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_27_86BD4(fnBase* p) {
    return !p->f3();
}
