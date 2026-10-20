#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Outer {
public:
    char pad[0xc];
    Inner inner;
};

extern "C" void fn_27_1AB058(Outer* self) {
    self->inner.f4();
}
