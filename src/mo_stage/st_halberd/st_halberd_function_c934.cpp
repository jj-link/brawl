#pragma force_active on

struct Value {
    int first;
    int second;
};

struct Array {
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
    virtual Value* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_57_C934(Array* self, const Value* value) {
    int full;
    int capacity;
    int last;

    last = self->v78();
    capacity = self->v74();
    full = self->v3C();
    bool isFull = self->v40();

    int index = unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, isFull, full, capacity, last);
    *self->v70(index) = *value;
    self->v7C(self->size() + 1);
}
