#pragma force_active on
typedef signed int s32;

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* ref, s32 b, s32 c);

class Self {
public:
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual s32 g3() = 0;
    virtual void* g4() = 0;
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
    virtual void g29(s32 n) = 0;
};

extern "C" void fn_47_62B4(Self* self) {
    s32 b;
    s32 a;
    a = self->g28();
    b = self->g13();
    void* c = self->g4();
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((void*)((char*)self + 4), c, b, a);
    s32 d = self->g3();
    self->g29(d - 1);
}
