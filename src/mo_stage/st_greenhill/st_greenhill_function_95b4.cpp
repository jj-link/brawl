#pragma force_active on

struct Item {
    int a;
    int b;
};

class Array {
public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
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
    virtual Item* at(int);
    virtual int getTopIndex();
    virtual int getLastIndex();
    virtual void setSize(int);

    int calculator;
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_72_95B4(Array* self, const Item* value) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calculator, self->v40(), self->v3C(), self->getTopIndex(), self->getLastIndex());

    *self->at(index) = *value;
    self->setSize(self->size() + 1);
}
