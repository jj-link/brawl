#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, void* b, int c, int d);

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
    virtual void* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
    virtual void f14();
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
    virtual void f26();
    virtual int f27();
    virtual void f28();
    virtual void f29(int n);
};

extern "C" void fn_27_75E68(Obj* self) {
    int b;
    int c;
    c = self->f27();
    b = self->f13();
    void* a = self->f4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), a, b, c);
    self->f29(self->f3() - 1);
}
