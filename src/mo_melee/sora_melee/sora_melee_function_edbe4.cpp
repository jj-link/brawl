#pragma force_active on
typedef signed int s32;

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, soArrayVectorCalcInterface* iface, s32 a, s32 b);

class Base {
public:
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual s32 f5() = 0;
    virtual soArrayVectorCalcInterface* f6() = 0;
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
    virtual void f31(s32 v) = 0;
};

extern "C" void fn_27_EDBE4(Base* self) {
    s32 r31;
    s32 r30;
    r30 = self->f29();
    r31 = self->f15();
    soArrayVectorCalcInterface* p = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, p, r31, r30);
    self->f31(self->f5() - 1);
}
