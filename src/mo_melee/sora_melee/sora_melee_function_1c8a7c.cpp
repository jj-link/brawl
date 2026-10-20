#pragma force_active on
class soInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};

class soOuter {
public:
    unsigned char pad[0x10];
    soInner inner;
};

extern "C" {
void fn_27_1C8A7C(soOuter* self) {
    self->inner.f8();
}
}
