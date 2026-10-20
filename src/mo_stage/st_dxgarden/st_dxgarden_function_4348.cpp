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

extern "C" void fn_77_4348(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    Element* e = self->at(pos);
    for (int i = 0; i < 19; i++) e->a[i] = value->a[i];
    e->f0 = value->f0;
    e->f1 = value->f1;
    e->f2 = value->f2;
    for (int i = 0; i < 6; i++) e->b[i] = value->b[i];
    e->s = value->s;
    e->c0 = value->c0;
    e->c1 = value->c1;
    e->c2 = value->c2;
    self->setSize(self->size() + 1);
}
