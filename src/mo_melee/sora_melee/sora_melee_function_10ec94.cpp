#pragma force_active on

struct Item {
    int a;
    int b;
    short c;
    short d;
};

struct soArrayVectorCalcInterface {};

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    soArrayVectorCalcInterface&, bool, long, long, long);

class Array {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int size();
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
    virtual Item* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    soArrayVectorCalcInterface calc;
};

extern "C" void fn_27_10EC94(Array* self, const Item* value) {
    *self->v70(unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        self->calc, self->v40(), self->v3C(), self->v74(), self->v78())) = *value;
    self->v7C(self->size() + 1);
}
