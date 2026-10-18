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
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual bool v14();
    virtual void v15();
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
    virtual Item* at(int);
    virtual int v27();
    virtual int v28();
    virtual void setSize(int);

    int calc;
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_63_C320(Obj* self, const Item* value) {
    int idx = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, self->v14(), self->v13(), self->v27(), self->v28());
    *self->at(idx) = *value;
    self->setSize(self->size() + 1);
}
