#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* ref, int b, int c);

class Obj {
public:
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual int f5() = 0;
    virtual void* f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual int f15() = 0;
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
    virtual int f29() = 0;
    virtual void f30() = 0;
    virtual void f31(int v) = 0;
};

extern "C" void fn_27_5459C(Obj* self) {
    int b;
    int c = self->f29();
    b = self->f15();
    void* ref = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, ref, b, c);
    self->f31(self->f5() - 1);
}
