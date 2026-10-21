#pragma force_active on
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void target();
};

struct Outer {
    char padding[0x10];
    Inner inner;
};

extern "C" void fn_27_D9E04(Outer* self) {
    self->inner.target();
}
