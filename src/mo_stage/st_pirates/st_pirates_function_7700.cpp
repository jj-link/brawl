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

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_52_7700(Array* self, const Element* value) {
    int pos = unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->v40(), self->v3c(), self->v74(), self->v78());
    Element* e = self->at(pos);
    e->a[0] = value->a[0]; e->a[1] = value->a[1]; e->a[2] = value->a[2];
    e->a[3] = value->a[3]; e->a[4] = value->a[4]; e->a[5] = value->a[5];
    e->a[6] = value->a[6]; e->a[7] = value->a[7]; e->a[8] = value->a[8];
    e->a[9] = value->a[9]; e->a[10] = value->a[10]; e->a[11] = value->a[11];
    e->a[12] = value->a[12]; e->a[13] = value->a[13]; e->a[14] = value->a[14];
    e->a[15] = value->a[15]; e->a[16] = value->a[16]; e->a[17] = value->a[17];
    e->a[18] = value->a[18];
    e->f0 = value->f0;
    e->f1 = value->f1;
    e->f2 = value->f2;
    e->b[0] = value->b[0]; e->b[1] = value->b[1]; e->b[2] = value->b[2];
    e->b[3] = value->b[3]; e->b[4] = value->b[4]; e->b[5] = value->b[5];
    e->s = value->s;
    e->c0 = value->c0;
    e->c1 = value->c1;
    e->c2 = value->c2;
    self->setSize(self->size() + 1);
}
