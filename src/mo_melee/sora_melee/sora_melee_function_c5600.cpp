#pragma force_active on

typedef int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* self, s32 arg0, s32 arg1, s32 arg2);

class CalcObj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual s32 f3() = 0;
    virtual s32 f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual s32 f13() = 0;
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
    virtual s32 f28() = 0;
    virtual void f29(s32) = 0;
};

extern "C" void fn_27_C5600(CalcObj* self) {
    s32 v13, v28;
    v28 = self->f28();
    v13 = self->f13();
    s32 v4 = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, v4, v13, v28);
    s32 v3 = self->f3();
    self->f29(v3 - 1);
}
