#pragma force_active on
extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, int, int, int);

class Obj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual int f3() = 0;
    virtual int f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual int f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual int f28() = 0;
    virtual void f29(int) = 0;
};

extern "C" void fn_27_10EF68(Obj* self) {
    int b, a;
    a = self->f28();
    b = self->f13();
    int c = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(self + 1, c, b, a);
    int d = self->f3();
    self->f29(d - 1);
}
