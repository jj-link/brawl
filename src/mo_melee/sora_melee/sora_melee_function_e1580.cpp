#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, int c, int d);

class Obj {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual int f5();
    virtual void* f6();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual int f15();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual int f29();
    virtual void d28();
    virtual void f31(int n);
};

extern "C" void fn_27_E1580(Obj* self) {
    int b;
    int a;
    a = self->f29();
    b = self->f15();
    void* r = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r, b, a);
    int n = self->f5();
    self->f31(n - 1);
}
