#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface &, bool, long, long);
};

class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual long v5();
    virtual soArrayVectorCalcInterface &v6();
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

extern "C" void fn_96_1F260(Obj *self) {
    long unused;
    self->calc.shift(self->v6(), self->v15(), self->v29(), unused);
    self->v31(self->v5() - 1);
}
