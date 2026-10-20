#pragma force_active on

struct Skip {
    virtual void unused();
};

struct Pair {
    unsigned int x, y;

    Pair& operator=(const Pair& p) {
        x = p.x;
        y = p.y;
        return *this;
    }
};

struct Embedded {
    virtual void unused();
    Skip calculator;
    unsigned int size;
    Pair pairs[6];
};

struct Element {
    unsigned int a0, a1, a2, a3, a4;
    unsigned int a5, a6, a7, a8, a9;
    Embedded embedded;
    unsigned char b0, b1;
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

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_66_C3D0(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());

    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
