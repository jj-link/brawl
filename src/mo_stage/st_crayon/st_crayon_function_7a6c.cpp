#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class soArrayVectorCalculator {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual void f29();
    virtual s32 f30();
    virtual void f31(s32 x);
    void* m4;
};

extern "C" void fn_56_7A6C(soArrayVectorCalculator* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)&self->m4, self->f6(), self->f15(), self->f30());
    self->f31(self->f5() - 1);
}
