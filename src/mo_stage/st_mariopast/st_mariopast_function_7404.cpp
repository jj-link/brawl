#pragma force_active on

struct Item {
    int a;
    int b;
};

struct Obj {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual int v14();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual int v3C();
    virtual int v40();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual Item* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

extern "C" void fn_48_7404(Obj* self, void* iface, const Item* src) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, self->v40(), self->v14(), self->v3C(), self->v74(), self->v78());
    *self->v70(pos) = *src;
    self->v7C(self->v14() + 1);
}