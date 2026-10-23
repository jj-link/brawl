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

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_4D140(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    Element* d = self->at(pos);
    d->a[0] = value->a[0];
    d->a[1] = value->a[1];
    d->a[2] = value->a[2];
    d->a[3] = value->a[3];
    d->a[4] = value->a[4];
    d->a[5] = value->a[5];
    d->a[6] = value->a[6];
    d->a[7] = value->a[7];
    d->a[8] = value->a[8];
    d->a[9] = value->a[9];
    d->a[10] = value->a[10];
    d->a[11] = value->a[11];
    d->a[12] = value->a[12];
    d->a[13] = value->a[13];
    d->a[14] = value->a[14];
    d->a[15] = value->a[15];
    d->a[16] = value->a[16];
    d->a[17] = value->a[17];
    d->a[18] = value->a[18];
    d->f0 = value->f0;
    d->f1 = value->f1;
    d->f2 = value->f2;
    d->b[0] = value->b[0];
    d->b[1] = value->b[1];
    d->b[2] = value->b[2];
    d->b[3] = value->b[3];
    d->b[4] = value->b[4];
    d->b[5] = value->b[5];
    d->s = value->s;
    d->c0 = value->c0;
    d->c1 = value->c1;
    d->c2 = value->c2;
    self->setSize(self->size() + 1);
}
