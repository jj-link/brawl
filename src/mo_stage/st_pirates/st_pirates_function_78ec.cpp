#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& a, bool b, long c, long d);
};

class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual long f3();
    virtual soArrayVectorCalcInterface& f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual bool f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual long f27();
    virtual void f28();
    virtual void f29(long v);
    soArrayVectorCalculator calc;
};

extern "C" {
void fn_52_78EC(Base* self) {
    long x;
    self->calc.shift(self->f4(), self->f13(), self->f27(), x);
    self->f29(self->f3() - 1);
}
}
