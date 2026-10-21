#pragma force_active on
typedef signed int s32;

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
    virtual s32 f4();
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
    virtual void f27();
    virtual s32 f28();
    virtual void f29(s32 n);
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, s32 a, s32 b, s32 c);

extern "C" void fn_57_CBE8(Obj* self) {
    s32 r31;
    s32 r30;
    r30 = self->f28();
    r31 = self->f13();
    s32 r4 = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, r4, r31, r30);
    s32 n = self->f3();
    self->f29(n - 1);
}
