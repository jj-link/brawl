#pragma force_active on
typedef signed int s32;

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& iface, bool b, long x, long y);
};

class Outer {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual s32 f5();
    virtual soArrayVectorCalcInterface* f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual bool f15();
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
    virtual void f27();
    virtual void f28();
    virtual long f29();
    virtual void f30();
    virtual void f31(long v);
    soArrayVectorCalculator calc;
};

extern "C" void fn_78_5AC0(Outer* self) {
    bool t31;
    long t30;
    t30 = self->f29();
    t31 = self->f15();
    soArrayVectorCalcInterface* r = self->f6();
    long unused;
    self->calc.shift(*r, t31, t30, unused);
    self->f31(self->f5() - 1);
}
