#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* a, s32 b, s32 c, s32 d);

class MyClass {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual s32 m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual s32 m27();
    virtual void m28();
    virtual void m29(s32);
};

extern "C" void fn_73_C948(MyClass* self) {
    s32 b;
    s32 a = self->m27();
    b = self->m13();
    s32 c = self->m4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4), c, b, a);
    s32 sz = self->m3();
    self->m29(sz - 1);
}
