#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class Arr {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual s32 v3() = 0;
    virtual s32 v4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual s32 v13() = 0;
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
    virtual s32 v28() = 0;
    virtual void v29(s32) = 0;
};

extern "C" void fn_27_1038BC(Arr* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4), self->v4(), self->v13(), self->v28());
    self->v29(self->v3() - 1);
}
