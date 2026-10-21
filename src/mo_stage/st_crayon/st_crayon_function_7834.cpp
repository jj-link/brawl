#pragma force_active on

typedef signed int s32;

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    soArrayVectorCalcInterface* a, s32 b, s32 c, s32 d);

class MyClass {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual s32 f5();
    virtual s32 f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual s32 f15();
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
    virtual s32 f29();
    virtual void f30();
    virtual void f31(s32);
};

extern "C" void fn_56_7834(MyClass* self) {
    s32 b;
    s32 a;
    a = self->f29();
    b = self->f15();
    s32 c = self->f6();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (soArrayVectorCalcInterface*)((char*)self + 4), c, b, a);
    s32 n = self->f5();
    self->f31(n - 1);
}
