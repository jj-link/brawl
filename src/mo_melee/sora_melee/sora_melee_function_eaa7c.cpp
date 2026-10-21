#pragma force_active on
typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, s32 b, s32 c, s32 d);

class MyClass {
public:
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual s32 g3() = 0;
    virtual s32 g4() = 0;
    virtual void g5() = 0;
    virtual void g6() = 0;
    virtual void g7() = 0;
    virtual void g8() = 0;
    virtual void g9() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual s32 g13() = 0;
    virtual void g14() = 0;
    virtual void g15() = 0;
    virtual void g16() = 0;
    virtual void g17() = 0;
    virtual void g18() = 0;
    virtual void g19() = 0;
    virtual void g20() = 0;
    virtual void g21() = 0;
    virtual void g22() = 0;
    virtual void g23() = 0;
    virtual void g24() = 0;
    virtual void g25() = 0;
    virtual void g26() = 0;
    virtual s32 g27() = 0;
    virtual void g28() = 0;
    virtual void g29(s32) = 0;
};

extern "C" {
void fn_27_EAA7C(MyClass* self) {
    s32 b;
    s32 a;
    a = self->g27();
    b = self->g13();
    s32 c = self->g4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, c, b, a);
    s32 d = self->g3();
    self->g29(d - 1);
}
}
