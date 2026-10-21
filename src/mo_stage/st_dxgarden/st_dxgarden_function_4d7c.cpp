#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class Foo {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 size();
    virtual s32 getLastIndex();
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
    virtual void f27();
    virtual s32 isEmpty();
    virtual void setSize(s32);
};

extern "C" void fn_77_4D7C(Foo* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4),
        self->getLastIndex(),
        self->capacity(),
        self->isEmpty()
    );
    self->setSize(self->size() - 1);
}
