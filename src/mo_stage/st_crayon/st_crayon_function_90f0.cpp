#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* ref, int a, int b);

class Owner {
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

extern "C" void fn_56_90F0(Owner* self) {
    int t31;
    int t30;
    t30 = self->f29();
    t31 = self->f15();
    void* ref = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, ref, t31, t30);
    int n = self->f5();
    self->f31(n - 1);
}
