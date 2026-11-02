#include <so/so_array.h>

#pragma force_active on

struct Element {
    float f0, f1, f2, f3;
    unsigned int a[7];
    unsigned short s0, s1;
    unsigned char c[11];
    unsigned int b[4];
    float f4;
    unsigned int d[4];
    float f5, f6, f7;
    unsigned int e[4];
    float f8;
    unsigned int g[5];
    float f9;
    unsigned int h;
    unsigned char z;
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

extern "C" void fn_54_6D70(Array* self, const Element* value) {
    int pos = soArrayVectorCalculator::push(
        *(soArrayVectorCalcInterface*)((char*)self + 4),
        self->v40(), self->v3c(), self->v74(), self->v78());
    Element* d = self->at(pos);

    d->f0 = value->f0;
    d->f1 = value->f1;
    d->f2 = value->f2;
    d->f3 = value->f3;
    d->a[0] = value->a[0];
    d->a[1] = value->a[1];
    d->a[2] = value->a[2];
    d->a[3] = value->a[3];
    d->a[4] = value->a[4];
    d->a[5] = value->a[5];
    d->a[6] = value->a[6];
    d->s0 = value->s0;
    d->s1 = value->s1;
    d->c[0] = value->c[0];
    d->c[1] = value->c[1];
    d->c[2] = value->c[2];
    d->c[3] = value->c[3];
    d->c[4] = value->c[4];
    d->c[5] = value->c[5];
    d->c[6] = value->c[6];
    d->c[7] = value->c[7];
    d->c[8] = value->c[8];
    d->c[9] = value->c[9];
    d->c[10] = value->c[10];
    d->b[0] = value->b[0];
    d->b[1] = value->b[1];
    d->b[2] = value->b[2];
    d->b[3] = value->b[3];
    d->f4 = value->f4;
    d->d[0] = value->d[0];
    d->d[1] = value->d[1];
    d->d[2] = value->d[2];
    d->d[3] = value->d[3];
    d->f5 = value->f5;
    d->f6 = value->f6;
    d->f7 = value->f7;
    d->e[0] = value->e[0];
    d->e[1] = value->e[1];
    d->e[2] = value->e[2];
    d->e[3] = value->e[3];
    unsigned int t = value->g[1];
    d->f8 = value->f8;
    d->g[0] = value->g[0];
    unsigned int t2 = value->g[2];
    d->g[1] = t;
    d->g[2] = t2;
    d->g[3] = value->g[3];
    d->g[4] = value->g[4];
    d->f9 = value->f9;
    d->h = value->h;
    d->z = value->z;

    self->setSize(self->size() + 1);
}
