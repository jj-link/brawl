#pragma force_active on
struct Element {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int w4;
    unsigned int w8;
    unsigned int wC;
    unsigned int w10;
    unsigned int w14;
    unsigned int w18;
    unsigned int w1C;
    unsigned int w20;
    unsigned int w24;
    unsigned int w28;
    unsigned int w2C;
    unsigned int w30;
    float f34;
    unsigned int w38;
    unsigned char b3C;
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
    virtual int capacity();
    virtual bool isFull();
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
    virtual int getTopIndex();
    virtual int getLastIndex();
    virtual void setSize(int);
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_EAD60(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->isFull(), self->size(),
        self->capacity(), self->getTopIndex(), self->getLastIndex());
    Element* d = self->at(pos);
    d->b0 = value->b0;
    d->w4 = value->w4;
    d->w8 = value->w8;
    d->wC = value->wC;
    d->w10 = value->w10;
    d->w14 = value->w14;
    d->w18 = value->w18;
    d->w1C = value->w1C;
    d->w20 = value->w20;
    d->w24 = value->w24;
    d->w28 = value->w28;
    d->w2C = value->w2C;
    d->w30 = value->w30;
    d->f34 = value->f34;
    d->w38 = value->w38;
    d->b3C = value->b3C;
    self->setSize(self->size() + 1);
}