#pragma force_active on
#pragma pack(4)

typedef unsigned int u32;

struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Nested : Base1, Base2 {
    u32 b0;
    Pair pairs[7];
};

struct Element {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    float f5;
    u32 w6;
    u32 w7;
    u32 w8;
    u32 w9;
    float fa;
    float fb;
    float fc;
    u32 wd;
    u32 we;
    u32 wf;
    u32 w10;
    Nested nested;
    u32 l0;
    u32 l1;
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

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_57_BAB4(Array* self, const Element* value) {
    int pos = unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->isFull(), self->capacity(), self->topIndex(), self->lastIndex());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
