#pragma force_active on
struct Element {
    float f00, f04, f08, f0c;
    unsigned int a10, a14, a18, a1c, a20, a24, a28;
    unsigned short s2c, s2e;
    unsigned char c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c3a;
    unsigned int a3c, a40, a44, a48;
    float f4c;
    unsigned int a50, a54, a58, a5c;
    float f60, f64, f68;
    unsigned int a6c, a70, a74, a78;
    float f7c;
    unsigned int a80, a84, a88, a8c, a90;
    float f94;
    unsigned int a98;
    unsigned char c9c;
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

extern "C" void fn_79_6394(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
