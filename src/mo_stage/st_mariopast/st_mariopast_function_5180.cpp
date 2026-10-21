#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, void*, s32, s32);

class Obj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual s32 f3() = 0;
    virtual void* f4() = 0;
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
    virtual void f29(s32 v) = 0;
    void* m_calc;
};

extern "C" void fn_48_5180(Obj* self) {
    s32 b;
    s32 a;
    a = self->f28();
    b = self->f13();
    void* c = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(&self->m_calc, c, b, a);
    self->f29(self->f3() - 1);
}
