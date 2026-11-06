#pragma force_active on

struct Item { int a; int b; };

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int v14();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int v3C();
    virtual int v40();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual Item* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v7C(int);
    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

extern "C" void fn_27_1B6958(Obj* self, void* iface, const Item* src) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, self->v40(), self->v14(), self->v3C(), self->v74(), self->v78());
    *self->v70(pos) = *src;
    self->v7C(self->v14() + 1);
}