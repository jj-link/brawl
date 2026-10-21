#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void pop(soArrayVectorCalcInterface& iface, bool b, long a, long c);
};

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
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
    virtual void f27();
    virtual long f28();
    virtual void f29(int n);
};

extern "C" void fn_40_20E2C(Obj* self) {
    bool r31;
    long r30;
    r30 = self->f28();
    r31 = self->f13();
    soArrayVectorCalcInterface& iface = self->f4();
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)((char*)self + 4);
    long unused;
    calc->pop(iface, r31, r30, unused);
    self->f29(self->f3() - 1);
}
