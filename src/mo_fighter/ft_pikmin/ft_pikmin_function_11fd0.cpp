#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface&, bool, long, long);
};

class FtPikminSelf {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual long v5();
    virtual soArrayVectorCalcInterface* v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool v15();
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
    virtual long v29();
    virtual void v30();
    virtual void v31(long);

    soArrayVectorCalculator calc;
};

extern "C" void fn_113_11FD0(FtPikminSelf* self) {
    bool t31;
    long t30;
    long d;
    t30 = self->v29();
    t31 = self->v15();
    soArrayVectorCalcInterface* iface = self->v6();
    self->calc.shift(*iface, t31, t30, d);
    long n = self->v5();
    self->v31(n - 1);
}
