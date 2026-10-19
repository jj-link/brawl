#pragma force_active on
struct FnBase77 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_77_3A3C(FnBase77* self) {
    return !self->f3();
}
