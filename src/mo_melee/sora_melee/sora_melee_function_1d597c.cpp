#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void*, s32, s32, s32);

class Foo {
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
    virtual void g27() = 0;
    virtual s32 g28() = 0;
    virtual void g29(s32) = 0;
};

extern "C" void fn_27_1D597C(Foo* self) {
    s32 cap, tmp;
    tmp = self->g28();
    cap = self->g13();
    s32 last = self->g4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (void*)((char*)self + 4), last, cap, tmp
    );
    s32 d = self->g3();
    self->g29(d - 1);
}
