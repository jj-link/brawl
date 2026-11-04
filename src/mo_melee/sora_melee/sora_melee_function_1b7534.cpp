#include <so/so_array.h>
#pragma force_active on

struct Entry {
    float x, y, z;
    unsigned char a, b, c, d, e;
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
    virtual int v3C();
    virtual bool v40();
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
    virtual Entry* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" void fn_27_1B7534(Array* self, const Entry* src) {
    int index = soArrayVectorCalculator::unshift(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc),
        self->v40(), self->v3C(), self->v74(), self->v78());
    Entry* dst = self->v70(index);
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    self->v7C(self->size() + 1);
}