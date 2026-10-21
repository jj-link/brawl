#pragma force_active on

typedef signed int s32;

class Obj {
public:
    virtual s32 f0() = 0;
    virtual s32 f1() = 0;
    virtual s32 f2() = 0;
    virtual s32 f3() = 0;
    virtual s32 f4() = 0;
    virtual s32 f5() = 0;
    virtual s32 f6() = 0;
    virtual s32 f7() = 0;
    virtual s32 f8() = 0;
    virtual s32 f9() = 0;
    virtual s32 f10() = 0;
    virtual s32 f11() = 0;
    virtual s32 f12() = 0;
    virtual s32 f13() = 0;
    virtual s32 f14() = 0;
    virtual s32 f15() = 0;
    virtual s32 f16() = 0;
    virtual s32 f17() = 0;
    virtual s32 f18() = 0;
    virtual s32 f19() = 0;
    virtual s32 f20() = 0;
    virtual s32 f21() = 0;
    virtual s32 f22() = 0;
    virtual s32 f23() = 0;
    virtual s32 f24() = 0;
    virtual s32 f25() = 0;
    virtual s32 f26() = 0;
    virtual s32 f27() = 0;
    virtual s32 f28() = 0;
    virtual void f29(s32) = 0;
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void*, s32, s32, s32);

extern "C" void fn_27_4D084(Obj* self) {
    s32 b;
    s32 a = self->f28();
    b = self->f13();
    s32 c = self->f4();

    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, c, b, a);

    self->f29(self->f3() - 1);
}
