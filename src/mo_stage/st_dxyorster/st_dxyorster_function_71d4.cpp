#pragma force_active on

struct Pair {
    int a;
    int b;
};

struct soArrayVectorCalcInterface {};

extern "C" int unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    soArrayVectorCalcInterface&, bool, long, long, long);

class Array {
public:
    virtual ~Array();
    virtual void f1();
    virtual void f2();
    virtual int v18();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int v40();
    virtual bool v44();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual Pair* v70(int);
    virtual int v74();
    virtual int v78();
    virtual void v80(int);

    soArrayVectorCalcInterface calc;
};

extern "C" void fn_76_71D4(Array* self, const Pair* value) {
    *self->v70(unshift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        self->calc, self->v44(), self->v40(), self->v74(), self->v78())) = *value;
    self->v80(self->v18() + 1);
}
