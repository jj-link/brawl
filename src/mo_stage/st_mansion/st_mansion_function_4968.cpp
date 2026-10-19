#pragma force_active on
struct stVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_47_4968(stVirtBase* p) {
    return !p->f3();
}
