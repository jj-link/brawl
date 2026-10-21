#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* calc, void* iface, s32 flag, s32 x);

class Self {
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
    s32 unk4;
};

extern "C" {
void fn_27_3906A0(Self* self) {
    s32 b;
    s32 a;
    a = self->f29();
    b = self->f15();
    void* c = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(&self->unk4, c, b, a);
    s32 n = self->f5();
    self->f31(n - 1);
}
}
