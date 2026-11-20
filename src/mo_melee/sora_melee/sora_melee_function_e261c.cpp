#pragma force_active on

struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Pair {
    unsigned int a, b;
    void operator=(const Pair& p) { a = p.a; b = p.b; }
};

struct Tail {
    Pair pairs[6];
};

struct Element {
    unsigned int f0, f1, f2, f3, f4, f5, f6, f7;
    Skip skipped;
    unsigned int middle;
    Tail tail;
    unsigned int last;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual bool slot14();
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
    virtual Element* slot26(int);
    virtual int slot27();
    virtual int slot28();
    virtual void slot29(int);
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_27_E261C(Object_vptr_0* __restrict self, Element* __restrict value) {
    int pos = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        (char*)self + 4, self->slot14(), self->slot13(), self->slot27(), self->slot28());
    *self->slot26(pos) = *value;
    self->slot29(self->slot3() + 1);
}
