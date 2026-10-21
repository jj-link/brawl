#pragma force_active on
class soArrayVectorCalcInterface {};

class soArrayVectorCalculator {
public:
    static void pop(soArrayVectorCalcInterface&, bool, long, long);
};

class soWorkBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual long f5();
    virtual bool f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual long f15();
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
    virtual void f31(long);
    soArrayVectorCalcInterface calc;
};

extern "C" void fn_27_1EA90(soWorkBase* self) {
    long value;
    long lv;
    lv = self->f30();
    value = self->f15();
    bool flag = self->f6();
    soArrayVectorCalculator::pop(self->calc, flag, value, lv);
    self->f31(self->f5() - 1);
}
