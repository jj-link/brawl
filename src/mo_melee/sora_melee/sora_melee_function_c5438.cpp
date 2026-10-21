#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, s32 c, s32 d);

class Base {
public:
    virtual void p0() = 0;
    virtual void p1() = 0;
    virtual void p2() = 0;
    virtual s32 f5() = 0;
    virtual void* f6() = 0;
    virtual void p7() = 0;
    virtual void p8() = 0;
    virtual void p9() = 0;
    virtual void p10() = 0;
    virtual void p11() = 0;
    virtual void p12() = 0;
    virtual void p13() = 0;
    virtual void p14() = 0;
    virtual s32 f15() = 0;
    virtual void p16() = 0;
    virtual void p17() = 0;
    virtual void p18() = 0;
    virtual void p19() = 0;
    virtual void p20() = 0;
    virtual void p21() = 0;
    virtual void p22() = 0;
    virtual void p23() = 0;
    virtual void p24() = 0;
    virtual void p25() = 0;
    virtual void p26() = 0;
    virtual void p27() = 0;
    virtual void p28() = 0;
    virtual s32 f29() = 0;
    virtual void p30() = 0;
    virtual void f31(s32 v) = 0;
};

extern "C" void fn_27_C5438(Base* self) {
    s32 b;
    s32 a;
    a = self->f29();
    b = self->f15();
    void* c = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, c, b, a);
    s32 n = self->f5();
    self->f31(n - 1);
}
