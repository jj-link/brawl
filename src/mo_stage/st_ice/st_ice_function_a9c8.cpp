#pragma force_active on
typedef signed int s32;

class Self {
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
    virtual s32 f27() = 0;
    virtual void f28() = 0;
    virtual void f29(s32 x) = 0;
};

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, s32 c, s32 d);

extern "C" void fn_62_A9C8(Self* self) {
    s32 r31;
    s32 r30;
    r30 = self->f27();
    r31 = self->f13();
    void* r4 = self->f4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r4, r31, r30);
    s32 r = self->f3();
    self->f29(r - 1);
}
