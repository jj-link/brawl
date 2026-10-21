#pragma force_active on

struct Item {
    int a;
    int b;
    short c;
    short d;
};

struct Obj {
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int v3c();
    virtual bool v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual Item* get(int);
    virtual int v74();
    virtual int v78();
    virtual void v7c(int);

    int calc;
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_27_10EE5C(Obj* self, const Item* src) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, self->v40(), self->v3c(), self->v74(), self->v78());
    *self->get(index) = *src;
    self->v7c(self->size() + 1);
}
