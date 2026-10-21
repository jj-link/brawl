#pragma force_active on
typedef int s32;

class soArrayVectorCalcInterface;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void* self, soArrayVectorCalcInterface* ref, s32 flag, s32 a);

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual s32 s3();
    virtual soArrayVectorCalcInterface* s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual s32 s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual s32 s28();
    virtual void s29(s32 n);
};

extern "C" void fn_49_B2D0(Obj* self) {
    s32 b;
    s32 a = self->s28();
    b = self->s13();
    soArrayVectorCalcInterface* r = self->s4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, r, b, a);
    s32 n = self->s3();
    self->s29(n - 1);
}
