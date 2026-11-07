#pragma force_active on

struct Item {
    int a;
    int b;
};

struct Obj {
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
    virtual int v40();
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
    virtual Item* get(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

extern "C" void fn_27_EB5AC(Obj* self, void* iface, const Item* src) {
    int d, c, b, a, e;
    a = self->v78();
    b = self->v74();
    c = self->v3C();
    d = self->size();
    e = self->v40();
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, e, d, c, b, a);
    *self->get(pos) = *src;
    self->v7C(self->size() + 1);
}
