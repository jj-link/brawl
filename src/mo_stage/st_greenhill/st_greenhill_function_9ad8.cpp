#pragma force_active on
struct StVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_72_9AD8(StVirtBase* p) {
    return !p->f3();
}
