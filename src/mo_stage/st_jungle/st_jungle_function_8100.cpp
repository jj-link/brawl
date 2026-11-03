#include <so/so_array.h>
#pragma force_active on

struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& rhs) { a = rhs.a; b = rhs.b; return *this; }
};
struct Nested : Base1, Base2 { u32 b0; Pair pairs[6]; };
struct Element {
    u32 a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
    Nested nested;
    unsigned char f0,f1;
};
class Array {
public:
    virtual void v08(); virtual void v0c(); virtual void v10();
    virtual int size();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual int capacity(); virtual bool isFull();
    virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6c();
    virtual Element* at(int);
    virtual int topIndex(); virtual int lastIndex(); virtual void setSize(int);
};
extern "C" void fn_51_8100(Array* self, const Element* value) {
    int pos = soArrayVectorCalculator::unshift(
        *(soArrayVectorCalcInterface*)((char*)self + 4), self->isFull(),
        self->capacity(), self->topIndex(), self->lastIndex());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}