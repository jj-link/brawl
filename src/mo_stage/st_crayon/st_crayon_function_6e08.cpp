#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void pop(soArrayVectorCalcInterface& a, bool b, long c, long d);
};

class Owner {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual long f5();
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
    virtual void f29();
    virtual long f30();
    virtual void f31(long n);

    soArrayVectorCalculator calc;
};

extern "C" void fn_56_6E08(Owner* self) {
    long unset;
    self->calc.pop(*self->f6(), self->f15(), self->f30(), unset);
    long n = self->f5();
    self->f31(n - 1);
}
