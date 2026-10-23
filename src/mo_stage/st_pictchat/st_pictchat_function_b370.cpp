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

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, bool, int, int, int, int);

extern "C" void fn_73_B370(Array* self, void* index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    Element* e = self->at(pos);
    e->a0 = value->a0; e->a1 = value->a1; e->a2 = value->a2; e->a3 = value->a3;
    e->a4 = value->a4; e->a5 = value->a5; e->a6 = value->a6; e->a7 = value->a7;
    e->a8 = value->a8; e->a9 = value->a9; e->a10 = value->a10; e->a11 = value->a11;
    e->a12 = value->a12; e->a13 = value->a13; e->a14 = value->a14; e->a15 = value->a15;
    e->a16 = value->a16; e->a17 = value->a17; e->a18 = value->a18;
    e->f0 = value->f0;
    e->f1 = value->f1;
    e->f2 = value->f2;
    e->b0 = value->b0; e->b1 = value->b1; e->b2 = value->b2;
    e->b3 = value->b3; e->b4 = value->b4; e->b5 = value->b5;
    e->s = value->s;
    e->c0 = value->c0;
    e->c1 = value->c1;
    e->c2 = value->c2;
    self->setSize(self->size() + 1);
}
