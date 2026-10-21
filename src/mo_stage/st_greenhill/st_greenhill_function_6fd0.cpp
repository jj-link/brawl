#pragma force_active on
typedef int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class Base {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual s32 g3();
    virtual s32 g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual s32 g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual s32 g28();
    virtual void g29(s32 n);
};

extern "C" void fn_72_6FD0(Base* self) {
    s32 hi;
    s32 lo;
    lo = self->g28();
    hi = self->g13();
    s32 r4 = self->g4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), r4, hi, lo);
    s32 n = self->g3();
    self->g29(n - 1);
}
