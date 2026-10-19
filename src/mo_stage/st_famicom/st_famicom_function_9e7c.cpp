#pragma force_active on
struct FnBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_68_9E7C(FnBase* p) {
    return !p->f3();
}
