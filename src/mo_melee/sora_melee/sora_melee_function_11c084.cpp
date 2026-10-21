#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, s32 c, s32 d);

class Base {
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
    virtual s32 f29() = 0;
    virtual void f30() = 0;
    virtual void f31(s32 n) = 0;
};

extern "C" void fn_27_11C084(Base* self) {
    s32 b;
    s32 a;
    a = self->f29();
    b = self->f15();
    void* t4 = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, t4, b, a);
    self->f31(self->f5() - 1);
}
