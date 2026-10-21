#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& a, bool b, long c, long d);
};

class Owner {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual long f5() = 0;
    virtual soArrayVectorCalcInterface& f6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual bool f15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual long f29() = 0;
    virtual void v30() = 0;
    virtual void f31(long n) = 0;
};

extern "C" void fn_62_712C(Owner* self) {
    bool b;
    long c;
    long d;
    c = self->f29();
    b = self->f15();
    soArrayVectorCalcInterface& a = self->f6();
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)((char*)self + 4);
    calc->shift(a, b, c, d);
    long n = self->f5();
    self->f31(n - 1);
}
