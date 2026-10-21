#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, void*, s32, s32);

class Obj {
public:
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual s32 f5() = 0;
    virtual void* f6() = 0;
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
    void* m_calc;
};

extern "C" void fn_27_122E9C(Obj* self) {
    s32 b;
    s32 a;
    void* c;
    a = self->f30();
    b = self->f15();
    c = self->f6();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)&self->m_calc, c, b, a);
    self->f31(self->f5() - 1);
}
