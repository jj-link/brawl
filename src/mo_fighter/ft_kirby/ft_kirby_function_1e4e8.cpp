#pragma force_active on
extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, int b, int c, int d);

struct Obj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
    virtual int s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual int s13();
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
    virtual int s27();
    virtual void s28();
    virtual void s29(int);
};

extern "C" void fn_96_1E4E8(Obj* self) {
    int b;
    int a = self->s27();
    b = self->s13();
    int c = self->s4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(self + 1, c, b, a);
    self->s29(self->s3() - 1);
}
