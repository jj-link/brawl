#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& iface, bool b, long a, long c);
};

class Self {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual long get5();
    virtual soArrayVectorCalcInterface* get6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool get15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual long get29();
    virtual void v30();
    virtual void set31(long n);
    soArrayVectorCalculator calc;
};

extern "C" void fn_27_105424(Self* self) {
    bool b;
    long a;
    long junk;
    a = self->get29();
    b = self->get15();
    soArrayVectorCalcInterface* c = self->get6();
    self->calc.shift(*c, b, a, junk);
    long n = self->get5();
    self->set31(n - 1);
}
