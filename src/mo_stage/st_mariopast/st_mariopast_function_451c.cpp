#pragma force_active on
typedef signed int s32;

class Self {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual s32 f5();
    virtual void* f6();
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
    virtual void f31(s32 n);
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* iface, s32 b, s32 l);

extern "C" void fn_48_451C(Self* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), self->f6(), self->f15(), self->f30());
    s32 n = self->f5();
    self->f31(n - 1);
}
