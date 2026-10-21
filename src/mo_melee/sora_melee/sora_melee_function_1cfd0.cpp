#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* iface, s32 b, s32 c);

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
    virtual void* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual s32 f13();
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
    virtual s32 f27();
    virtual void f28();
    virtual void f29(s32 n);
};

extern "C" void fn_27_1CFD0(Obj* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->f4(), self->f13(), self->f27());
    self->f29(self->f3() - 1);
}
