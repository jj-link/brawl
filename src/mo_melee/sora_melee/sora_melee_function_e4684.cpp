#pragma force_active on
#include <so/so_array_vector_calculator.h>

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Mid : Base1, Base2 {
    unsigned int pad0;
    Pair pairs[7];
};

struct Element {
    int f00, f04, f08, f0c, f10;
    float f14;
    int f18, f1c, f20, f24;
    float f28, f2c, f30;
    int f34, f38, f3c, f40;
    Mid mid;
    Pair last;
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

extern "C" void fn_27_E4684(Array* self, const Element* value) {
    int pos = soArrayVectorCalculator::push(
        *(soArrayVectorCalcInterface*)((char*)self + 4), self->isFull(), self->capacity(), self->topIndex(), self->lastIndex());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
