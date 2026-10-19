#pragma force_active on
struct fn_76_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_76_794C(fn_76_Base* self) {
    return !self->f3();
}
