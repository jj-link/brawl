#pragma force_active on

struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Pair {
    unsigned int a, b;
    ~Pair() {}
};

struct PairArray {
    Pair pairs[6];
};

struct Element {
    unsigned int a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
    Skip skip;
    unsigned int a12;
    PairArray array;
    unsigned char b0,b1;

    Element& operator=(const Element& rhs) {
        a0=rhs.a0; a1=rhs.a1; a2=rhs.a2; a3=rhs.a3; a4=rhs.a4;
        a5=rhs.a5; a6=rhs.a6; a7=rhs.a7; a8=rhs.a8; a9=rhs.a9;
        a12=rhs.a12;
        array=rhs.array;
        b0=rhs.b0; b1=rhs.b1;
        return *this;
    }
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

extern "C" void fn_68_8DF4(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
