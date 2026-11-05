#pragma force_active on
#include <so/so_array.h>

struct Element {
    unsigned int a[4];
    float f10;
    unsigned int b[4];
    float f24, f28, f2c;
    unsigned int c[11];
    unsigned short s;
    unsigned char c5e, c5f;
    unsigned int d;
    unsigned char c64;
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

extern "C" void fn_27_DF0F8(Array* self, const Element* value) {
    int pos = soArrayVectorCalculator::unshift(
        *(soArrayVectorCalcInterface*)((char*)self + 4),
        self->v40(), self->v3c(), self->v74(), self->v78());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
