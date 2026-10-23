#pragma force_active on
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

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_DF608(Array* self, int index, const Element* value) {
    int t14;
    int t3c;
    int t74;
    int t78;
    t78 = self->v78();
    t74 = self->v74();
    t3c = self->v3c();
    t14 = self->size();
    bool t40 = self->v40();
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, t40, t14, t3c, t74, t78);
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
