#pragma force_active on

#include <types.h>
#include <so/so_array.h>
#include <so/so_array_vector_calculator.h>

struct Item {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

class Array {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int capacity();
    virtual bool isFull();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual Item* at(int);
    virtual int getTopIndex();
    virtual int getLastIndex();
    virtual void setSize(int);

    int calc;
};

extern "C" void fn_70_A620(Array* self, s32 index, const Item* value) {
    s32 pos = soArrayVectorCalculator::insert(
        *(soArrayVectorCalcInterface*)&self->calc, index, self->isFull(), self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
