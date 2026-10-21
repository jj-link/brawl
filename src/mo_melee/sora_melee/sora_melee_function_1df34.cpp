#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void pop(soArrayVectorCalcInterface& iface, bool b, long x, long y);
};

class Obj {
public:
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual long f5() = 0;
    virtual soArrayVectorCalcInterface& f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual bool f15() = 0;
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
    virtual long f30() = 0;
    virtual void f31(long v) = 0;
    soArrayVectorCalculator calc;
};

extern "C" void fn_27_1DF34(Obj* self) {
    long c;
    self->calc.pop(self->f6(), self->f15(), self->f30(), c);
    self->f31(self->f5() - 1);
}
