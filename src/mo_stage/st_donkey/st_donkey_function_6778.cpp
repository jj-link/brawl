#pragma force_active on
struct Element {
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18;
    float f0, f1, f2;
    unsigned int b0, b1, b2, b3, b4, b5;
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

extern "C" void fn_50_6778(Array* self, const Element* value) {
    int pos = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->v40(), self->v3c(), self->v74(), self->v78());
    Element* d = self->at(pos);
    d->a0 = value->a0; d->a1 = value->a1; d->a2 = value->a2; d->a3 = value->a3;
    d->a4 = value->a4; d->a5 = value->a5; d->a6 = value->a6; d->a7 = value->a7;
    d->a8 = value->a8; d->a9 = value->a9; d->a10 = value->a10; d->a11 = value->a11;
    d->a12 = value->a12; d->a13 = value->a13; d->a14 = value->a14; d->a15 = value->a15;
    d->a16 = value->a16; d->a17 = value->a17; d->a18 = value->a18;
    d->f0 = value->f0; d->f1 = value->f1; d->f2 = value->f2;
    d->b0 = value->b0; d->b1 = value->b1; d->b2 = value->b2;
    d->b3 = value->b3; d->b4 = value->b4; d->b5 = value->b5;
    d->s = value->s;
    d->c0 = value->c0; d->c1 = value->c1; d->c2 = value->c2;
    self->setSize(self->size() + 1);
}
