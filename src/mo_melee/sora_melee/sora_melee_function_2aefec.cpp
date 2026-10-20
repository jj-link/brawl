#pragma force_active on
extern "C" int fn_27_2AD89C(void* self);

class soFoo {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual unsigned int f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
};

extern "C" void* fn_27_2AEFEC(soFoo* self) {
    int idx = fn_27_2AD89C(self);
    if (self->f4() != 1 && idx >= 0) {
        self->f13();
    }
    return (char*)self + idx * 12 + 0x10;
}
