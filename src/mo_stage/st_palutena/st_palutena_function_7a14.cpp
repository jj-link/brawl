#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* arr, s32 a, s32 b, s32 c);

class Self {
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
    virtual void f29(s32 x) = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    void* m_arr;
};

extern "C" void fn_67_7A14(Self* self) {
    s32 t31;
    s32 t30;
    t30 = self->f28();
    t31 = self->f13();
    s32 t6 = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(&self->m_arr, t6, t31, t30);
    s32 t5 = self->f3();
    self->f29(t5 - 1);
}
