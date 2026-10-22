#pragma force_active on
typedef signed int s32;
extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, s32 b, s32 c, s32 d);

class soArrayVectorCalculatorBase {
public:
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual s32 f5() = 0;
    virtual s32 f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual s32 f15() = 0;
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
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual s32 f30() = 0;
    virtual void f31(s32) = 0;
};

extern "C" void fn_40_1ECB4(soArrayVectorCalculatorBase* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, self->f6(), self->f15(), self->f30());
    s32 sz = self->f5();
    self->f31(sz - 1);
}
