#pragma force_active on

typedef signed int s32;

class CalcIf {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual s32 size() = 0;
    virtual bool isEmpty() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual s32 getA() = 0;
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
    virtual s32 getB() = 0;
    virtual void setSize(s32) = 0;
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, bool b, s32 c, s32 d);

extern "C" void fn_27_AE8A8(CalcIf* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, self->isEmpty(), self->getA(), self->getB());
    self->setSize(self->size() - 1);
}
