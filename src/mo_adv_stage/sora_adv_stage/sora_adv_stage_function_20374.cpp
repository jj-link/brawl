#pragma force_active on
class soArrayVectorCalcInterface {};

class soArrayVectorCalculator {
public:
    static void pop(soArrayVectorCalcInterface&, bool, long, long);
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual long v13();
    virtual void v14();
    virtual void v15();
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
    virtual long v28();
    virtual void v29(int n);
    soArrayVectorCalcInterface calc;
};

extern "C" void fn_40_20374(Owner* self) {
    soArrayVectorCalculator::pop(self->calc, self->v4(), self->v13(), self->v28());
    int n = self->v3();
    self->v29(n - 1);
}
