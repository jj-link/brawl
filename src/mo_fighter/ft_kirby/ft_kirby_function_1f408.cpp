#pragma force_active on
typedef int s32;

struct Iface {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
};

struct Calc {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual s32 size();
    virtual s32 empty();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual s32 capacity();
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual s32 lastIndex();
    virtual void setSize(s32);
    Iface iface;
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    Iface& iface, s32 empty, s32 capacity, s32 lastIndex);

extern "C" void fn_96_1F408(Calc* self) {
    s32 last = self->lastIndex();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        self->iface, self->empty(), self->capacity(), last);
    self->setSize(self->size() - 1);
}
