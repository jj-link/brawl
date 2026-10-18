#pragma force_active on
struct Entry {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

struct Object {
    virtual void pad08();
    virtual void pad0c();
    virtual void pad10();
    virtual int size();
    virtual void pad18();
    virtual void pad1c();
    virtual void pad20();
    virtual void pad24();
    virtual void pad28();
    virtual void pad2c();
    virtual void pad30();
    virtual void pad34();
    virtual void pad38();
    virtual int v3c();
    virtual bool v40();
    virtual void pad44();
    virtual void pad48();
    virtual void pad4c();
    virtual void pad50();
    virtual void pad54();
    virtual void pad58();
    virtual void pad5c();
    virtual void pad60();
    virtual void pad64();
    virtual void pad68();
    virtual void pad6c();
    virtual Entry* at(int);
    virtual int v74();
    virtual int v78();
    virtual void setSize(int);

    int calc;
};

extern "C" int
unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, long, long, long);

extern "C" void fn_79_6B88(Object* self, const Entry* src) {
    int index =
        unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
            &self->calc, self->v40(), self->v3c(), self->v74(), self->v78());
    *self->at(index) = *src;
    self->setSize(self->size() + 1);
}
