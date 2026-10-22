#pragma force_active on
typedef signed int s32;

class Foo {
public:
    virtual void f0();                // slot 0
    virtual void f1();                // slot 1
    virtual void f2();                // slot 2
    virtual s32 size() const;         // slot 3   -> 0x14
    virtual s32 isEmpty() const;      // slot 4   -> 0x18
    virtual void f4();                // slot 5
    virtual void f5();                // slot 6
    virtual void f6();                // slot 7
    virtual void f7();                // slot 8
    virtual void f8();                // slot 9
    virtual void f9();                // slot 10
    virtual void f10();               // slot 11
    virtual void f11();               // slot 12
    virtual s32 capacity() const;     // slot 13  -> 0x3c
    virtual void f13();               // slot 14
    virtual void f14();               // slot 15
    virtual void f15();               // slot 16
    virtual void f16();               // slot 17
    virtual void f17();               // slot 18
    virtual void f18();               // slot 19
    virtual void f19();               // slot 20
    virtual void f20();               // slot 21
    virtual void f21();               // slot 22
    virtual void f22();               // slot 23
    virtual void f23();               // slot 24
    virtual void f24();               // slot 25
    virtual void f25();               // slot 26
    virtual void f26();               // slot 27
    virtual s32 getLastIndex() const; // slot 28  -> 0x78
    virtual void setSize(s32);        // slot 29  -> 0x7c
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

extern "C" void fn_62_71E8(Foo* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4),
        self->isEmpty(),
        self->capacity(),
        self->getLastIndex()
    );
    self->setSize(self->size() - 1);
}
