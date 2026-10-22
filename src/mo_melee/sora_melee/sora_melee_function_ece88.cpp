#pragma force_active on

struct Item {
    unsigned char a;
    int b;
    int c;
    unsigned char d;
    unsigned char e;
    int f;
    int g;
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

extern "C" void fn_27_ECE88(Obj* self, void* iface, const Item* src) {
    int index = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, self->v40(), self->size(), self->v3C(), self->v74(), self->v78());
    *self->get(index) = *src;
    self->v7C(self->size() + 1);
}
