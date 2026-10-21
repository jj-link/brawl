#pragma force_active on

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, bool b, long c, long d);

class SoArrayVecCalc {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual int f3() = 0;
    virtual bool f4() = 0;
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
    virtual int f27() = 0;
    virtual void f28() = 0;
    virtual void f29(int n) = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
};

extern "C" void fn_27_E356C(SoArrayVecCalc* self) {
    int b;
    int a = self->f27();
    b = self->f13();
    bool c = self->f4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), c, b, a);
    self->f29(self->f3() - 1);
}
