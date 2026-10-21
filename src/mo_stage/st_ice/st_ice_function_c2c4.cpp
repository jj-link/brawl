#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, s32 a, s32 b, s32 c);

class Base {
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
    virtual void f29();
    virtual s32 f30();
    virtual void f31(s32 x);
};

extern "C" void fn_62_C2C4(Base* self) {
    s32 t15;
    s32 t30;
    s32 t6;
    t30 = self->f30();
    t15 = self->f15();
    t6 = self->f6();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, t6, t15, t30);
    self->f31(self->f5() - 1);
}
