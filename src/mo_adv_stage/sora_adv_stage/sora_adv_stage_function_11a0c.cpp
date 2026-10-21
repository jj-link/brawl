#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void pop(soArrayVectorCalcInterface& iface, bool b, long l1, long l2);
};

class Outer {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual long f3();
    virtual soArrayVectorCalcInterface* f4();
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
    virtual void f27();
    virtual long f28();
    virtual void f29(long n);
    soArrayVectorCalculator calc;
};

extern "C" void fn_40_11A0C(Outer* self) {
    bool r31;
    long r30;
    r30 = self->f28();
    r31 = self->f13();
    soArrayVectorCalcInterface* p = self->f4();
    long junk;
    self->calc.pop(*p, r31, r30, junk);
    self->f29(self->f3() - 1);
}
