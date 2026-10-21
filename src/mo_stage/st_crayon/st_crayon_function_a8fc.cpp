#pragma force_active on

typedef signed int s32;

class soArrayVectorCalcInterface;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    soArrayVectorCalcInterface* a, s32 b, s32 c, s32 d);

class MyClass {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 size();
    virtual s32 isEmpty();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual s32 capacity();
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
    virtual s32 getTopIndex();
    virtual void f28();
    virtual void setSize(s32);
};

extern "C" void fn_56_A8FC(MyClass* self) {
    s32 b;
    s32 a = self->getTopIndex();
    b = self->capacity();
    s32 c = self->isEmpty();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (soArrayVectorCalcInterface*)((char*)self + 4), c, b, a);
    s32 sz = self->size();
    self->setSize(sz - 1);
}
