#pragma force_active on
#include <types.h>

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

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
    virtual void f29(s32);
};

extern "C" void fn_27_390FC(Obj* self) {
    s32 a, b;
    b = self->f28();
    a = self->f13();
    s32 c = self->f4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((u8*)self + 4), c, a, b);
    s32 t4 = self->f3();
    self->f29(t4 - 1);
}
