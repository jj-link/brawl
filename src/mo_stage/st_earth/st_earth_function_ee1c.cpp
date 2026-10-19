#pragma force_active on
struct VBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_66_EE1C(VBase* p) {
    return !p->f3();
}
