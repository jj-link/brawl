#pragma force_active on

struct Item {
    int a;
    int b;
};

struct Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int v14();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int v3C();
    virtual int v40();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual Item* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);

    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

extern "C" void fn_54_AD4C(Obj* self, void* iface, const Item* src) {
    int e, d, c, b, a;
    a = self->v78();
    b = self->v74();
    c = self->v3C();
    d = self->v14();
    e = self->v40();
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, e, d, c, b, a);
    *self->v70(pos) = *src;
    self->v7C(self->v14() + 1);
}
