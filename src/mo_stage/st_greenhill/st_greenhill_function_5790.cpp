#pragma force_active on
struct Element {
    float f00, f04, f08, f0c;
    unsigned int a10, a14, a18, a1c, a20, a24, a28;
    unsigned short s2c, s2e;
    unsigned char c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c3a;
    unsigned int a3c, a40, a44, a48;
    float f4c;
    unsigned int a50, a54, a58, a5c;
    float f60, f64, f68;
    unsigned int a6c, a70, a74, a78;
    float f7c;
    unsigned int a80, a84, a88, a8c, a90;
    float f94;
    unsigned int a98;
    unsigned char c9c;
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

extern "C" void fn_72_5790(Array* self, const Element* value) {
    int c3c, c74, c78;
    bool c40;
    c78 = self->v78();
    c74 = self->v74();
    c3c = self->v3c();
    c40 = self->v40();
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, c40, c3c, c74, c78);
    Element* d = self->at(index);

    d->f00 = value->f00;
    d->f04 = value->f04;
    d->f08 = value->f08;
    d->f0c = value->f0c;
    d->a10 = value->a10;
    d->a14 = value->a14;
    d->a18 = value->a18;
    d->a1c = value->a1c;
    d->a20 = value->a20;
    d->a24 = value->a24;
    d->a28 = value->a28;
    d->s2c = value->s2c;
    d->s2e = value->s2e;
    d->c30 = value->c30;
    d->c31 = value->c31;
    d->c32 = value->c32;
    d->c33 = value->c33;
    d->c34 = value->c34;
    d->c35 = value->c35;
    d->c36 = value->c36;
    d->c37 = value->c37;
    d->c38 = value->c38;
    d->c39 = value->c39;
    d->c3a = value->c3a;
    d->a3c = value->a3c;
    d->a40 = value->a40;
    d->a44 = value->a44;
    d->a48 = value->a48;
    d->f4c = value->f4c;
    d->a50 = value->a50;
    d->a54 = value->a54;
    d->a58 = value->a58;
    d->a5c = value->a5c;
    d->f60 = value->f60;
    d->f64 = value->f64;
    d->f68 = value->f68;
    d->a6c = value->a6c;
    d->a70 = value->a70;
    d->a74 = value->a74;
    d->a78 = value->a78;
    unsigned int w80 = value->a80;
    d->f7c = value->f7c;
    unsigned int w84 = value->a84;
    d->a80 = w80;
    unsigned int w88 = value->a88;
    d->a84 = w84;
    unsigned int w8c = value->a8c;
    d->a88 = w88;
    unsigned int w90 = value->a90;
    d->a8c = w8c;
    float w94 = value->f94;
    d->a90 = w90;
    unsigned int w98 = value->a98;
    d->f94 = w94;
    unsigned char w9c = value->c9c;
    d->a98 = w98;
    d->c9c = w9c;

    self->setSize(self->size() + 1);
}
