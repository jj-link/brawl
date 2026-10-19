#pragma force_active on
struct fn27Inner {
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
    virtual void f10();
};

struct fn27Outer {
    int unk0;
    fn27Inner unk4;
};

extern "C" {
void fn_27_C428C(fn27Outer* self) {
    self->unk4.f8();
    self->unk0 = -1;
}
}
