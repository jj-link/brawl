#pragma force_active on
struct Entry {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

struct soArrayVectorCalcInterface {
    int value;
};

struct soArrayVectorCalculator {
    static long push(soArrayVectorCalcInterface&, bool, long, long, long);
};

struct Array {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual long size();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual long v3c();
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
    virtual Entry* v70(long);
    virtual long v74();
    virtual long v78();
    virtual void v7c(long);

    soArrayVectorCalcInterface calc;
};

extern "C" void fn_56_78F0(Array* self, const Entry& entry) {
    long index = soArrayVectorCalculator::push(
        self->calc, self->v40(), self->v3c(), self->v74(), self->v78());
    *self->v70(index) = entry;
    self->v7c(self->size() + 1);
}
