#pragma force_active on
struct Element {
    unsigned int a[19];
    float f0, f1, f2;
    unsigned int b[6];
    short s;
    unsigned char c0, c1, c2;
};

class Array {
public:
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
    virtual Element* at(int);
    virtual int v74();
    virtual int v78();
    virtual void setSize(int);
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_56_9EFC(Array* self, const Element* value) {
    int pos = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->v40(), self->v3c(), self->v74(), self->v78());
    Element* d = self->at(pos);
    for (int i = 0; i < 19; i++) d->a[i] = value->a[i];
    d->f0 = value->f0;
    d->f1 = value->f1;
    d->f2 = value->f2;
    for (int i = 0; i < 6; i++) d->b[i] = value->b[i];
    d->s = value->s;
    d->c0 = value->c0;
    d->c1 = value->c1;
    d->c2 = value->c2;
    self->setSize(self->size() + 1);
}
