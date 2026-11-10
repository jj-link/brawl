#pragma force_active on

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Nested : Base1, Base2 {
    unsigned int b0;
    Pair pairs[7];
};

struct Element {
    unsigned int a0, a1, a2, a3, a4;
    float f14;
    unsigned int a6, a7, a8, a9;
    float f28, f2c, f30;
    unsigned int a13, a14, a15, a16;
    Nested nested;
    unsigned int l0, l1;
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
    virtual int topIndex();
    virtual int lastIndex();
    virtual void setSize(int);
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_62_580C(Array* self, const Element* value) {
    int pos = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->isFull(), self->capacity(), self->topIndex(), self->lastIndex());
    Element* d = self->at(pos);
    *d = *value;
    self->setSize(self->size() + 1);
}