#pragma force_active on

struct Element {
    float f0;
    float f1;
    float f2;
    char c0;
    char c1;
    char c2;
    char c3;
    char c4;
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
    virtual Element* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_1B7904(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3C(), self->v74(), self->v78());
    *self->v70(pos) = *value;
    self->v7C(self->size() + 1);
}
