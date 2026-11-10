#pragma force_active on

struct Rec {
    int base;
    int field4;
    int field8;
    short fieldC;
    short fieldE;
};

class soArrayVectorCalcInterface {
public:
    virtual void x00();
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    soArrayVectorCalcInterface*, bool, int, int, int);

extern "C" void fn_27_77588(Rec* dst, const Rec* src);

class Array {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int v3C();
    virtual bool v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual Rec* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    soArrayVectorCalcInterface calc;
};

extern "C" void fn_27_DE288(Array* self, const Rec* src) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, self->v40(), self->v3C(), self->v74(), self->v78());
    Rec* dst = self->v70(index);
    fn_27_77588(dst, src);
    dst->field8 = src->field8;
    dst->fieldC = src->fieldC;
    dst->fieldE = src->fieldE;
    self->v7C(self->v14() + 1);
}
