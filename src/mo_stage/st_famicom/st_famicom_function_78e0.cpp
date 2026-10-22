#pragma force_active on

struct Item {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

struct Obj {
    virtual void v08();
    virtual void v0c();
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
    virtual Item* at(int);
    virtual int v74();
    virtual int v78();
    virtual void v7c(int);

    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, long, bool, int, int, int, int);

extern "C" void fn_68_78E0(Obj* self, long idx, const Item* value) {
    int index =
        insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
            &self->calc, idx, self->v40(), self->size(), self->v3c(), self->v74(), self->v78());
    *self->at(index) = *value;
    self->v7c(self->size() + 1);
}
