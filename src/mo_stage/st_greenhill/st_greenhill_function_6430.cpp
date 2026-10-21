#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, int c, int d);

class Obj {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
    virtual void* f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int f15();
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
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual int f29();
    virtual void f30();
    virtual void f31(int n);
};

extern "C" void fn_72_6430(Obj* self) {
    int b;
    int a = self->f29();
    b = self->f15();
    void* c = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, c, b, a);
    int n = self->f5();
    self->f31(n - 1);
}
