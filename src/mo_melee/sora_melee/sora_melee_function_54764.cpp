#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void pop(soArrayVectorCalcInterface& iface, bool b, long l1, long l2);
};

class Self {
public:
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual long f5();
    virtual soArrayVectorCalcInterface* f6();
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10() {}
    virtual void d11() {}
    virtual void d12() {}
    virtual void d13() {}
    virtual void d14() {}
    virtual bool f15();
    virtual void d16() {}
    virtual void d17() {}
    virtual void d18() {}
    virtual void d19() {}
    virtual void d20() {}
    virtual void d21() {}
    virtual void d22() {}
    virtual void d23() {}
    virtual void d24() {}
    virtual void d25() {}
    virtual void d26() {}
    virtual void d27() {}
    virtual void d28() {}
    virtual void d29() {}
    virtual long f30();
    virtual void f31(long n);
};

extern "C" void fn_27_54764(Self* self) {
    bool b;
    long a;
    a = self->f30();
    b = self->f15();
    soArrayVectorCalcInterface* iface = self->f6();
    long u;
    ((soArrayVectorCalculator*)((char*)self + 4))->pop(*iface, b, a, u);
    self->f31(self->f5() - 1);
}
