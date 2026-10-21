#pragma force_active on

typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* self, s32 a, s32 b, s32 c);

class Arr {
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

extern "C" void fn_27_11BC68(Arr* self) {
    s32 b;
    s32 a;
    a = self->f28();
    b = self->f13();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4), self->f4(), b, a);
    s32 n = self->f3();
    self->f29(n - 1);
}
