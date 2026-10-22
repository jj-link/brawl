#pragma force_active on

struct Item {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

struct soArrayVectorCalcInterface {};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, soArrayVectorCalcInterface&, bool, long, long, long, long);

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
    virtual Item* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    soArrayVectorCalcInterface calc;
};

extern "C" void fn_74_7F0C(Array* self, soArrayVectorCalcInterface& iface, const Item* value) {
    int t29;
    int t28;
    int t27;
    int t26;
    t26 = self->v78();
    t27 = self->v74();
    t28 = self->v3C();
    t29 = self->size();
    bool b = self->v40();
    int index = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, b, t29, t28, t27, t26);
    *self->v70(index) = *value;
    self->v7C(self->size() + 1);
}
